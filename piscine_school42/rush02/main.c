#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "rush_02.h"
#include "s_ditem.h"
#include "s_dpow.h"

int main(int argc, char **argv)
{
	char buf[129]; //для чтения словаря
	char *filename;
	char *output_str;

	s_ditem 	*list_ditem;
	s_dpow 		*list_dpow;

	list_dpow = 0;
	list_ditem = 0;

	// читаем входные параметры
	if (argc == 3)
	{
		filename = argv[1];
		output_str = argv[2];
	}
	else if (argc == 2)
	{
		filename = "numbers.dict.txt";
		output_str = argv[1];
	}
	else
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!ft_str_is_numeric(output_str))
	{
		ft_putstr("error\n");
		return (0);
	}


	// читаем словарь
	int fd = open(filename, O_RDONLY);
	char *str;
	int strlen = 0;
	int len;
	str = "\0";
	len = read(fd, &buf, 127);
	while (len == 127)
	{
	    buf[128] = '\0';
	    //процессим буффер. там может быть ситуация, когда в буффере только половина строки, нам надо это првильно обрабатывать
	    //поэтому возвращаем длину строки, которая осталась (обнуляем внутри длину при переходе на новую строчку)
        strlen = process_input_buf(buf, len, &str, strlen, &list_ditem, &list_dpow);
        if (strlen == -1)
        {
            //если что-то пошло не так, ашибка
            ft_putstr("dict error\n");
            return (0);
        }
        len = read(fd, &buf, 127);
	}
	//обрабатываем оставшиеся в буффере символы
    strlen = process_input_buf(buf, len, &str, strlen, &list_ditem, &list_dpow);
	close(fd);

	//дебаг вывод словаря, чтобы убедиться, что все ок выводится
	printf("DITEM LIST: \n");
	s_ditem_print_list(&list_ditem);
	printf("DPOW LIST: \n");
    s_dpow_print_list(&list_dpow);

    //переходим к обработке входной строки и превращаем ее в слова
    process_output(output_str, &list_ditem, &list_dpow);
}

