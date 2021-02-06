/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:16:09 by machanse          #+#    #+#             */
/*   Updated: 2021/01/27 16:21:04 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		size;
	char	*result;

	size = 0;
	while (*(str + size))
		size += 1;
	result = malloc(sizeof(str) + 1);
	size = 0;
	while (str[size])
	{
		result[size] = str[size];
		size += 1;
	}
	result[size] = '\0';
	return (result);
}
