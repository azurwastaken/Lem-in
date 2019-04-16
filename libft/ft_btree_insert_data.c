/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:02:10 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 11:34:38 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root,
		void *item, int (*cmpf)(void *, void *))
{
	t_btree *node;

	if (!*root)
	{
		*root = ft_btree_create_node(item);
		return ;
	}
	node = *root;
	if (cmpf(item, node->item) < 0)
	{
		if (node->left)
			ft_btree_insert_data(&node->left, item, cmpf);
		else
			node->left = ft_btree_create_node(item);
	}
	else
	{
		if (node->right)
			ft_btree_insert_data(&node->right, item, cmpf);
		else
			node->right = ft_btree_create_node(item);
	}
}
