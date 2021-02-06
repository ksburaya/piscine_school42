/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:04:59 by machanse          #+#    #+#             */
/*   Updated: 2021/01/20 17:28:34 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	a;
	int		counter;

	a = 97;
	counter = 26;
	while (counter != 0)
	{
		write(1, &a, 1);
		--counter;
		++a;
	}
}
