/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:10:38 by machanse          #+#    #+#             */
/*   Updated: 2021/02/04 17:11:06 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	element->data = data;
	element->next = 0;
	return (element);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_element;
	t_list	*tmp;

	if (!*begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	new_element = ft_create_elem(data);
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_element;
}

int		get_tree_max_level(t_btree *root, int level)
{
	int result;

	if (root->left)
	{
		result = get_tree_max_level(root->left, level + 1);
		return (level > result ? level : result);
	}
	if (root->right)
	{
		result = get_tree_max_level(root->right, level + 1);
		return (level > result ? level : result);
	}
	return (level);
}

void	create_lists(t_btree *root, t_list **levels, int level)
{
	ft_list_push_back(levels + level, root->item);
	if (root->left)
		create_lists(root->left, levels, level + 1);
	if (root->right)
		create_lists(root->right, levels, level + 1);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
		int current_level, int is_first_elem))
{
	int		level;
	t_list	**levels;
	t_list	*pointer;
	int		i;
	int		is_first;

	level = get_tree_max_level(root, 1);
	levels = malloc(sizeof(t_list *) * level);
	create_lists(root, levels, 0);
	i = 0;
	while (i < level)
	{
		pointer = levels[i];
		is_first = 1;
		while (pointer)
		{
			(*applyf)(pointer->data, i, is_first);
			pointer = pointer->next;
			is_first = 0;
		}
		i += 1;
	}
}
