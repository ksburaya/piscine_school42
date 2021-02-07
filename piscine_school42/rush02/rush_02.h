#ifndef RUSH02_RUSH_02_H
# define RUSH02_RUSH_02_H

#include "ft.h"
#include "s_ditem.h"
#include "s_dpow.h"

int 	check_line(char *str, s_ditem **list_ditem, s_dpow **list_dpow)
{
	//TODO save correct lines to dict
	char **split_result = ft_split(str, " :");
	int len = 0;
	while (*(split_result + len))
		len += 1;
	if (len != 2)
		return (0);

	char *number = split_result[0];
	char *value  = split_result[1];


	//check 0..9
	if (ft_strlen(number) == 1 && ft_str_is_numeric(number))
	{
		s_ditem_list_push_back(list_ditem, number, value);
		return (1);
	}
	//check 10..19
	else if (ft_strlen(number) == 2 && number[0] == '1' && ft_str_is_numeric(number + 1))
	{
        s_ditem_list_push_back(list_ditem, number, value);
        return (1);
	}
	//check 20, 30....90
	else if (ft_strlen(number) == 2 && number[0] >= '2' && number[0] <= '9' && number[1] == '0')
	{
        s_ditem_list_push_back(list_ditem, number, value);
        return (1);
	}
	//check 100
	else if (ft_strcmp(number, "100") == 0)
	{
        s_ditem_list_push_back(list_ditem, number, value);
        return (1);
	}
	//check power of 1000
	else if (ft_strlen(number) >= 3 && number[0] == '1')
	{
		int index = 1;
		while (number[index] && number[index] == '0')
			index += 1;
		if (index == ft_strlen(number) && (index - 1) % 3 == 0)
		{
			s_dpow_list_push_back(list_dpow, (index - 1) / 3, value);
			return (1);
		}
	}
	return (0);
}

int     process_input_buf(char *buf, int len, char **str, int strlen,
                          s_ditem **list_ditem, s_dpow **list_dpow)
{
    int i;
    char *line;

    i = 0;
    while (i < len)
    {
        while (buf[i] && ft_strncmp(buf + i, "\n", 1) != 0)
        {
            strlen += 1;
            i += 1;
        }
        line = malloc(sizeof(char) * (strlen + 1));
        if (ft_strlen(*str) == 0)
            line = ft_strncpy(line, buf + i - strlen, strlen);
        else
        {
            //если у нас осталась строка с предыдушего раза -- надо ее не забыть учесть
            int prev_str_len = ft_strlen(*str);
            line = ft_strncpy(line, *str, prev_str_len);
            line = ft_strncpy(line + prev_str_len, buf + i - strlen + prev_str_len, strlen - prev_str_len);
            line -= prev_str_len;
            *str = "\0";
        }
        line[strlen] = '\0';
        //функция проверяет строку на валидность формату {}:{} и записывает в список, если она ок
        check_line(line, list_ditem, list_dpow);
        strlen = 0;
        i += 1;
        free(line);
    }
    if (ft_strlen(line) > 0)
    {
        //запоминаем оставшийся кусочек строки
        *str = malloc(sizeof(char) * (ft_strlen(line) + 1));
        *str = ft_strncpy(*str, line, ft_strlen(line));
    }
    return ft_strlen(line);
}

void    one_symbol_case(char *ch, s_ditem **list_ditem)
{
    //конструируем паттерн, ищем его
    char *to_find = malloc(2 * sizeof (char));
    to_find[0] = ch[0];
    to_find[1] = '\0';
    char *result = s_ditem_find_value(list_ditem, to_find);
    ft_putstr(result);
    ft_putstr(" ");
}

void    two_sybmol_case(char *ch, s_ditem **list_ditem)
{
    char *to_find = malloc(sizeof(char) * 3);
    if (*ch == '1')
    {
        //есди у нас 10-19, то это один куйс
        *to_find = *ch;
        *(to_find + 1) = *(ch + 1);
        *(to_find + 2) = '\0';
        char *result = s_ditem_find_value(list_ditem, to_find);
        ft_putstr(result);
        ft_putstr(" ");
    }
    else if (*ch != '0')
    {
        //если у нас число вида x * 10, то другой кейс
        *to_find = *ch;
        *(to_find + 1) = '0';
        *(to_find + 2) = '\0';
        char *result = s_ditem_find_value(list_ditem, to_find);
        ft_putstr(result);
        ft_putstr(" ");
        one_symbol_case(ch + 1, list_ditem);
    }
    else //иначе у нас нет десятков, переходим к обработкам единиц в числе
        one_symbol_case(ch + 1, list_ditem);

}

void    three_symbol_case(char *ch, s_ditem **list_ditem)
{
    if (*ch != '0') {
        //если у нас есть количество сотен, то выводим их
        one_symbol_case(ch, list_ditem);
        char *hundreds = s_ditem_find_value(list_ditem, "100");
        ft_putstr(hundreds);
        ft_putstr(" ");
    }
    //дальше выводим число без сотен
    //если сотен 0, то есть число вида 041, то сразу переходим к 41
    two_sybmol_case(ch + 1, list_ditem);
}
void    process_output(char *output, s_ditem **list_ditem, s_dpow **list_dpow)
{
    int pow;
    int size;
    char *tmp;

    size = ft_strlen(output);
    //условно разбиваем нашу строку на тройки с конца, обрабатываем с начала
    //например 10141: 10 и 141, сначала обрабатываем 10, потом 141
    while (size != 0)
    {
        if (size <= 3)
            pow = 0;
        else
            pow = size / 3; //how many 1000 we need to figure out
        if (size % 3 == 0)
        {
            //если у нас три символа
            three_symbol_case(output, list_ditem);
            //сдвигаем нашу входную строку и убираем то, что уже обработали
            tmp = malloc(sizeof(char) * (size - 3));
            tmp = ft_strncpy(tmp, output + 3, size - 3);
        }
        else if (size % 3 == 2)
        {
            two_sybmol_case(output, list_ditem);
            tmp = malloc(sizeof(char) * (size - 2));
            tmp = ft_strncpy(tmp, output + 2, size - 2);
        }
        else if (size % 3 == 1)
        {
            one_symbol_case(output, list_ditem);
            tmp = malloc(sizeof(char) * (size - 2));
            tmp = ft_strncpy(tmp, output + 1, size - 1);
            size -= 1;
        }

        //проверяем, есть ли у нас нужная степень 1000
        char *pow_str = s_dpow_find_value(list_dpow, pow);
        if (pow_str)
        {
            ft_putstr(pow_str);
            ft_putstr(" ");
        }
        //сдвигаем число, начинаем заново
        output = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
        output = ft_strncpy(output, tmp, ft_strlen(tmp));
        output[ft_strlen(tmp)] = '\0';
        size = ft_strlen(output);
    }
}
#endif //RUSH02_RUSH_02_H
