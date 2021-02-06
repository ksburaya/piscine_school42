/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 17:34:04 by machanse          #+#    #+#             */
/*   Updated: 2021/01/27 17:34:07 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				*p;
	unsigned int	i;
	unsigned int	result;

	p = NULL;
	if (min >= max)
	{
		*range = p;
		return (0);
	}
	p = malloc(sizeof(int*) * (max - min));
	if (!p)
		return (-1);
	result = max - min;
	i = 0;
	while (min < max)
	{
		p[i++] = min;
		min += 1;
	}
	*range = p;
	return (result);
}
