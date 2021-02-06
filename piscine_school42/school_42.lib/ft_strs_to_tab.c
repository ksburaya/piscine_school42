/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:13:49 by machanse          #+#    #+#             */
/*   Updated: 2021/01/30 15:14:02 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str != '\0')
	{
		str += 1;
		len += 1;
	}
	return (len);
}

char				*ft_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			index;
	t_stock_str	*result;

    result = malloc(sizeof(t_stock_str) *(ac + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (index < ac)
	{
		result[index].size = ft_strlen(av[index]);
		result[index].str = malloc(sizeof(char) * (result[index].size + 1));
		result[index].copy = malloc(sizeof(char) * (result[index].size + 1));
		if (!result[index].str || !result[index].copy)
			return (NULL);
		result[index].str = ft_strcpy(result[index].str, av[index]);
		result[index].str = ft_strcpy(result[index].copy, result[index].str);
		index += 1;
	}
	result[index].str = 0;
	return (result);
}
