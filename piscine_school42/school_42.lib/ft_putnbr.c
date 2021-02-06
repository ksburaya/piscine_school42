/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:02:14 by machanse          #+#    #+#             */
/*   Updated: 2021/01/25 12:19:41 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned int nb)
{
	char	c;

	c = nb % 10 + 48;
	if (nb > 10)
	{
		ft_putchar(nb / 10);
	}
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	u_nb;

	if (nb < 0)
	{
		write(1, "-", 1);
		u_nb = -nb;
	}
	else
	{
		u_nb = nb;
	}
	ft_putchar(u_nb);
}
