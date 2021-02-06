/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:42:54 by machanse          #+#    #+#             */
/*   Updated: 2021/01/24 16:57:10 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_printline(char a, char b, char c, int x)
{
	int i;

	ft_putchar(a);
	i = 2;
	while (i < x)
	{
		ft_putchar(b);
		i++;
	}
	if (i == x)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 1;
	if (x > 0 && y > 0)
	{
		//ft_printline('A', 'B', 'C', x);
		i++;
		while (i < y)
		{
			//ft_printline('B', ' ', 'B', x);
			i++;
		}
		//if (i == y)
			//ft_printline('A', 'B', 'C', x);
	}
}
