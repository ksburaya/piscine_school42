/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:29:49 by machanse          #+#    #+#             */
/*   Updated: 2021/01/20 20:45:58 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_int(int c)
{
	write(1, &c, 4);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = -1;
	while (++i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_put_int(i / 10 + 48);
			ft_put_int(i % 10 + 48);
			write(1, " ", 1);
			ft_put_int(j / 10 + 48);
			ft_put_int(j % 10 + 48);
			if (i != 98 || j != 99)
			{
				write(1, ", ", 2);
			}
			++j;
		}
	}
}
