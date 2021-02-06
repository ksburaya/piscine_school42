/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:33:49 by machanse          #+#    #+#             */
/*   Updated: 2021/01/21 20:56:58 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void	ft_sort(int *tab, int l, int r)
{
	int m;
	int i;
	int j;

	m = (l + r) / 2;
	i = l;
	j = r;
	while (i <= j)
	{
		while (*(tab + i) < *(tab + m))
		{
			i++;
		}
		while (*(tab + j) > *(tab + m))
		{
			j--;
		}
		ft_swap(tab + i++, tab + j--);
		ft_sort(tab, l, j);
		ft_sort(tab, i, r);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_sort(tab, 0, size - 1);
}
