/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:02:15 by machanse          #+#    #+#             */
/*   Updated: 2021/01/27 13:02:18 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str += 1;
	}
}

void	ft_print_program_name(char **argv)
{
	ft_putstr(argv[0]);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	(void)argc;
	ft_print_program_name(argv);
}
