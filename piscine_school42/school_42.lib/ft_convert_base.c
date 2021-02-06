/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:01:13 by machanse          #+#    #+#             */
/*   Updated: 2021/01/28 18:15:56 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str);
int				ft_check_base(char *base);
int				ft_base_to_int(char *base, char c);
int				ft_getnb(char *str, char *base);
int				is_str_contains(char *str, char c);

char			*ft_get_nbr(char *nbr, char *base_from)
{
	char	*final_nbr;
	int		size;
	int		index;
	int		j;

	size = 0;
	j = 0;
	while (*(nbr + size) && is_str_contains(base_from, nbr[size]))
		size += 1;
	final_nbr = (char*)malloc(size + 1);
	index = 0;
	while (index < size)
	{
		final_nbr[index] = nbr[index];
		index += 1;
	}
	final_nbr[index] = '\0';
	return (final_nbr);
}

void			get_length(unsigned int nb, char *base, unsigned int *rl)
{
	char			c;
	unsigned int	size;

	size = ft_strlen(base);
	c = *(base + nb % size);
	if (nb >= size)
	{
		get_length(nb / size, base, rl);
	}
	*rl += 1;
}

void			ft_putchar(unsigned int nb, char *base, int step, char *result)
{
	char			c;
	unsigned int	size;

	size = ft_strlen(base);
	c = *(base + nb % size);
	if (nb >= size)
	{
		ft_putchar(nb / size, base, step - 1, result);
	}
	result[step] = c;
}

char			*result(char *nbr_from, char *b_from, char *b_to, int sign)
{
	unsigned int	result_length;
	unsigned int	int_base_10;
	char			*nbr_to;

	int_base_10 = ft_getnb(nbr_from, b_from);
	result_length = 0;
	get_length(int_base_10, b_to, &result_length);
	if (sign < 0)
		result_length += 1;
	nbr_to = (char *)malloc(result_length + 1);
	ft_putchar(int_base_10, b_to, result_length - 1, nbr_to);
	if (sign < 0)
		nbr_to[0] = '-';
	nbr_to[result_length] = '\0';
	return (nbr_to);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				sign;
	char			*nbr_from;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	sign = 1;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr += 1;
	}
	nbr_from = ft_get_nbr(nbr, base_from);
	if (ft_strlen(nbr_from) == 0)
		return (NULL);
	return (result(nbr_from, base_from, base_to, sign));
}
