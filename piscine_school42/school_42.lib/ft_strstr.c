/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:45:20 by machanse          #+#    #+#             */
/*   Updated: 2021/01/24 14:58:57 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len) != '\0')
	{
		len += 1;
	}
	return (len);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*(s1 + i) && *(s2 + i) && i < n && *(s1 + i) == *(s2 + i))
	{
		i += 1;
	}
	if (i == n)
	{
		return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		n;
	int		index;

	n = ft_strlen(to_find);
	index = 0;
	while (str[index])
	{
		if (ft_strncmp(str + index, to_find, n) == 0)
		{
			return (str + index);
		}
		index += 1;
	}
	return (str + index);
}
