/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:42:24 by machanse          #+#    #+#             */
/*   Updated: 2021/01/27 18:42:40 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*(str + size))
	{
		size += 1;
	}
	return (size);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(dest + i))
	{
		i += 1;
	}
	while (*src && j < n)
	{
		*(dest + i) = *src;
		i += 1;
		j += 1;
		src += 1;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int				i;
	unsigned int	total_size;
	char			*result;

	if (size == 0)
		return ("");
	i = 0;
	total_size = 0;
	while (i < size)
		total_size += ft_strlen(strs[i++]);
	result = malloc(total_size + (size - 1) * ft_strlen(sep) + 1);
	result[0] = '\0';
	i = 0;
	while (i < size - 1)
	{
		result = ft_strncat(result, strs[i], ft_strlen(strs[i]));
		result = ft_strncat(result, sep, ft_strlen(sep));
		i += 1;
	}
	result = ft_strncat(result, strs[i], ft_strlen(strs[i]));
	return (result);
}
