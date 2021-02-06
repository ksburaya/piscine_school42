#ifndef RUSH02_FT_H
#define RUSH02_FT_H

int		ft_strlen(char *str)
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

char	*ft_strcpy(char *dest, char *src)
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

int		ft_str_is_numeric(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i += 1;
			continue;
		}
		return (0);
	}
	return (1);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1 += 1;
		s2 += 1;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str += 1;
	}
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
	r[str_index] = (char *)0;
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

#endif //RUSH02_FT_H
