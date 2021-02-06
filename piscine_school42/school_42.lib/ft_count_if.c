/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:57:27 by machanse          #+#    #+#             */
/*   Updated: 2021/02/02 16:02:47 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			counter += 1;
		i += 1;
	}
	return (counter);
}
