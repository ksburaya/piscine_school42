/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:24:15 by machanse          #+#    #+#             */
/*   Updated: 2021/01/25 13:31:42 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_getnb(char *str)
{
	unsigned int	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		str += 1;
	}
	return (nb);
}

int		ft_atoi(char *str)
{
	int				sign;
	unsigned int	nb;

	sign = 1;
	while (*str == ' ')
		str += 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str += 1;
	}
	nb = ft_getnb(str);
	if (sign == -1)
		nb = -nb;
	return (nb);
}
