/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:35:23 by machanse          #+#    #+#             */
/*   Updated: 2021/01/20 19:26:18 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	pointer1;
	char	pointer2;
	char	pointer3;

	pointer1 = '0' - 1;
	while (++pointer1 <= '7')
	{
		pointer2 = pointer1;
		while (++pointer2 <= '8')
		{
			pointer3 = pointer2;
			while (++pointer3 <= '9')
			{
				write(1, &pointer1, 1);
				write(1, &pointer2, 1);
				write(1, &pointer3, 1);
				if (pointer1 != '7' || pointer2 != '8' || pointer3 != '9')
				{
					write(1, ", ", 2);
				}
			}
		}
	}
}
