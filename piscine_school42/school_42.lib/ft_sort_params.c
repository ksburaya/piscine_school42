/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:13:07 by machanse          #+#    #+#             */
/*   Updated: 2021/01/27 13:13:09 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str += 1;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
		i += 1;
	return (*(s1 + i) - *(s2 + i));
}

void	ft_swap(char **a, char **b)
{
	char *tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void	ft_sort(char **tab, int l, int r)
{
	char	*pivot;
	int		i;
	int		j;

	if (l < r)
	{
		pivot = tab[(l + r) / 2];
		i = l;
		j = r;
		while (i < j)
		{
			while (ft_strcmp(tab[i], pivot) < 0)
				i += 1;
			while (ft_strcmp(tab[j], pivot) > 0)
				j -= 1;
			if (i <= j)
				ft_swap(tab + i++, tab + j--);
		}
		if (j > l)
			ft_sort(tab, l, j);
		if (i < r)
			ft_sort(tab, i, r);
	}
}

int		main(int argc, char **argv)
{
	int	i;

	ft_sort(argv, 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i += 1;
	}
}
