#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "rush_02.h"
#include "s_ditem.h"
#include "s_dpow.h"

int main(int argc, char **argv)
{
	char *buf;
	char *filename;
	char *output_str;

	s_ditem 	*list_ditem;
	s_dpow 		*list_dpow;

	list_dpow = 0;
	list_ditem = 0;

	// TODO rewrite to separate function
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
	//ENDOF TODO

	int fd = open(filename, O_RDONLY);
	char *str;
	char *tmp;
	int strlen = 1;
	while (read(fd, &buf, 1) != 0)
	{
		if (ft_strcmp(buf, "\n") != 0)
		{
			tmp = malloc(sizeof(char) * (strlen + 1));
			ft_strcpy(tmp, str);
			str = tmp;
			str[strlen] = *buf;
			str[strlen + 1] = '\n';
			free(tmp);
		}
		else
		{
			check_line(str, &list_ditem, &list_dpow);
		}
	}
	close(fd);
}

