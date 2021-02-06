/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:02:48 by machanse          #+#    #+#             */
/*   Updated: 2021/01/24 16:04:59 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strncat(char *dest, char *src, unsigned int n)
{
    unsigned int    i;
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
    *(dest + i) = '\0';
    return (dest);
}
