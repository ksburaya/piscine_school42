/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:32:27 by machanse          #+#    #+#             */
/*   Updated: 2021/01/26 18:54:09 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_diagonal(int *current_state, int line, int position)
{
	int	d_index;

	d_index = 1;
	while (line - d_index >= 0)
	{
		if (current_state[line - d_index] == position - d_index)
		{
			return (0);
		}
		if (current_state[line - d_index] == position + d_index)
			return (0);
		d_index += 1;
	}
	return (1);
}

int		is_position_available(int *current_state, int line, int position)
{
	int index;

	index = 0;
	while (index < line)
	{
		if (current_state[index] == position)
		{
			return (0);
		}
		index += 1;
	}
	return (check_diagonal(current_state, line, position));
}

void	print_solution(int *current_state, int n)
{
	int	i;
	int c;

	i = 0;
	while (i < n)
	{
		c = current_state[i] + 48;
		write(1, &c, 1);
		i += 1;
	}
	write(1, "\n", 1);
}

void	find_next_position(int *current_state, int line, int *answer, int n)
{
	int	position;

	if (line == n)
	{
		print_solution(current_state, n);
		*answer += 1;
		return ;
	}
	position = 0;
	while (position < n)
	{
		if (is_position_available(current_state, line, position))
		{
			current_state[line] = position;
			find_next_position(current_state, line + 1, answer, n);
		}
		position += 1;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int start_position;
	int current_state[10];
	int answer;

	start_position = 0;
	answer = 0;
	find_next_position(current_state, 0, &answer, 10);
	return (answer);
}
