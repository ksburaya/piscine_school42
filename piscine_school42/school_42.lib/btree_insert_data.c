/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:04:56 by machanse          #+#    #+#             */
/*   Updated: 2021/02/04 15:19:33 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree	*cur;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	cur = *root;
	if ((*cmpf)(item, cur->item) < 0)
	{
		if (cur->left)
			btree_insert_data(&cur->left, item, cmpf);
		else
			cur->left = btree_create_node(item);
	}
	else if ((*cmpf)(item, cur->item) >= 0)
	{
		if (cur->right)
			btree_insert_data(&cur->right, item, cmpf);
		else
			cur->right = btree_create_node(item);
	}
}
