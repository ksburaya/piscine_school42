/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:59:43 by machanse          #+#    #+#             */
/*   Updated: 2021/02/04 16:59:54 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_tree_max_level(t_btree *root, int level)
{
	if (root->left)
		return (max(level, get_tree_max_level(root->left, level + 1)));
	if (root->right)
		return (max(level, get_tree_max_level(root->right, level + 1)));
	return (level);
}

int	btree_level_count(t_btree *root)
{
	return (get_tree_max_level(root, 1));
}
