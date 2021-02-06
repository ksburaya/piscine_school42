/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:28:10 by machanse          #+#    #+#             */
/*   Updated: 2021/01/25 16:29:25 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (*(str + size))
	{
		size += 1;
	}
	return (size);
}

void			ft_putchar(unsigned int nb, char *base)
{
	char			c;
	unsigned int	size;

	size = ft_strlen(base);
	c = *(base + nb % size);
	if (nb >= size)
	{
		ft_putchar(nb / size, base);
	}
	write(1, &c, 1);
}

int				ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*(base + i))
	{
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (0);
			j += 1;
		}
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		i += 1;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int	u_nb;

	if (!ft_check_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		u_nb = -nbr;
	}
	else
	{
		u_nb = nbr;
	}
	ft_putchar(u_nb, base);
}
