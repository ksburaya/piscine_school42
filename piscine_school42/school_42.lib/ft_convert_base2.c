/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:00:09 by machanse          #+#    #+#             */
/*   Updated: 2021/01/28 18:00:35 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int				ft_base_to_int(char *base, char c)
{
	int	index;

	index = 0;
	while (*(base + index) != c)
		index += 1;
	return (index);
}

int				ft_getnb(char *str, char *base)
{
	unsigned int	nb;
	int				base_size;
	int				power;

	nb = 0;
	base_size = ft_strlen(base);
	power = 1;
	str = str + ft_strlen(str) - 1;
	while (*str)
	{
		nb += power * ft_base_to_int(base, *str);
		str -= 1;
		power *= base_size;
	}
	return (nb);
}

int				is_str_contains(char *str, char c)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return (1);
		i += 1;
	}
	return (0);
}
