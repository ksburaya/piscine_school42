/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:49:09 by machanse          #+#    #+#             */
/*   Updated: 2021/01/26 15:59:06 by machanse         ###   ########.fr       */
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
