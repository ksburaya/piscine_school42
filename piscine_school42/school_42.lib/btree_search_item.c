/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machanse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:31:05 by machanse          #+#    #+#             */
/*   Updated: 2021/02/04 16:31:53 by machanse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	void *result;

	result = 0;
	if (root->left)
		result = btree_search_item(root->left, data_ref, cmpf);
	if (!result && (*cmpf)(root->item, data_ref) == 0)
		return (root);
	if (!result && root->right)
		result = btree_search_item(root->right, data_ref, cmpf);
	return (result);
}
