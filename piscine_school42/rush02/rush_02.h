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

	//check 0..9
	if (ft_strlen(number) == 1 && ft_str_is_numeric(number))
	{
		//TODO insert to s_ditem list
		(void)list_ditem;
		(void)list_dpow;
	}
	//check 10..19
	if (ft_strlen(number) == 2 && number[0] == '1' && ft_str_is_numeric(number + 1))
	{
		//TODO insert to s_ditem list
	}
	//check 20, 30....90
	if (ft_strlen(number) == 2 && number[0] >= '2' && number[0] <= '9' && number[1] == '0')
	{
		//TODO insert to s_ditem list
	}
	//check 100
	if (ft_strcmp(number, "100") == 0)
	{
		//TODO insert to s_ditem list
	}
	//check power of 1000
	if (ft_strlen(number) >= 3 && number[0] == '1')
	{
		int index = 1;
		while (number[index] && number[index] == '0')
			index += 1;
		if (index == ft_strlen(number) && index % 3 == 0)
		{
			//TODO insert to s_dpow list
		}
	}
	return (0);
}

#endif //RUSH02_RUSH_02_H
