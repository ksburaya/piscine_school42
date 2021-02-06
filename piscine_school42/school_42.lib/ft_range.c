/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:48:04 by machanse          #+#    #+#             */
/*   Updated: 2021/01/27 16:48:12 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*p;
	int	i;

	p = NULL;
	if (min >= max)
		return (p);
	p = malloc(sizeof(int*) * (max - min));
	i = 0;
	while (min < max)
	{
		p[i++] = min;
		min += 1;
	}
	return (p);
}
