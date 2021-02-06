/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:42:33 by machanse          #+#    #+#             */
/*   Updated: 2021/01/30 15:42:37 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(unsigned int nb)
{
	char	c;

	c = nb % 10 + 48;
	if (nb >= 10)
	{
		ft_putchar(nb / 10);
	}
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str += 1;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str)
	{
		ft_putstr(par[index].str);
		ft_putchar(par[index].size);
		write(1, "\n", 1);
		ft_putstr(par[index].copy);
		index += 1;
	}
}
