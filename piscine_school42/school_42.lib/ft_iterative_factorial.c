/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:39:41 by machanse          #+#    #+#             */
/*   Updated: 2021/01/26 12:50:00 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;
	int power;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	result = 1;
	power = 1;
	while (power <= nb)
	{
		result *= power;
		power += 1;
	}
	return (result);
}
