/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:02:01 by machanse          #+#    #+#             */
/*   Updated: 2021/01/26 16:11:45 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_min_delimiter(int nb)
{
	int delimiter;

	delimiter = 2;
	while (delimiter <= nb)
	{
		if (nb % delimiter == 0)
			return (delimiter);
		delimiter += 1;
	}
	return (delimiter);
}

int	ft_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	if (ft_get_min_delimiter(nb) != nb)
		return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int index;

	if (nb <= 1)
		nb = 2;
	index = 0;
	while (nb + index > 0)
	{
		if (ft_is_prime(nb + index))
			return (nb + index);
		index += 1;
	}
	return (2);
}
