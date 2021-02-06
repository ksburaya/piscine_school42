/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:33:03 by machanse          #+#    #+#             */
/*   Updated: 2021/01/28 20:40:27 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep_cur_char(char c, char *sep)
{
	int	i;

	i = 0;
	while (*(sep + i))
	{
		if (*(sep + i) == c)
			return (0);
		i += 1;
	}
	return (1);
}

int		get_total_strings(char *str, char *charset)
{
	int	counter;
	int	offset;

	counter = 0;
	offset = 0;
	while (*(str + offset))
	{
		while (*(str + offset) && is_sep_cur_char(*(str + offset), charset))
			offset += 1;
		counter += 1;
		while (*(str + offset) && !is_sep_cur_char(*(str + offset), charset))
			offset += 1;
	}
	return (counter);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index += 1;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index += 1;
	}
	return (dest);
}

void	get_result(char *str, char *charset, char **r)
{
	int		offset;
	int		str_index;
	int		size;

	size = 0;
	offset = 0;
	str_index = 0;
	while (*(str + offset))
	{
		while (*(str + offset) && is_sep_cur_char(*(str + offset), charset))
		{
			offset += 1;
			size += 1;
		}
		r[str_index] = (char *)malloc(sizeof(char) * (size + 1));
		r[str_index] = ft_strncpy(r[str_index], str + offset - size, size);
		str_index += 1;
		size = 0;
		while (*(str + offset) && !is_sep_cur_char(*(str + offset), charset))
			offset += 1;
	}
	r[str_index] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		total_strings;

	total_strings = get_total_strings(str, charset);
	result = (char**)malloc(sizeof(char*) * (total_strings + 1));
	get_result(str, charset, result);
	return (result);
}
