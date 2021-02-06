/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:08:06 by machanse          #+#    #+#             */
/*   Updated: 2021/01/24 16:16:29 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(dest + i))
	{
		i += 1;
	}
	while (*src && j < size)
	{
		*(dest + i) = *src;
		i += 1;
		j += 1;
		src += 1;
	}
	*(dest + i) = '\0';
	return (i);
}
