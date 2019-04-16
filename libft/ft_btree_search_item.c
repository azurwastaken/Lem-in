/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:03:05 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 11:37:30 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	t_btree *node;

	node = 0;
	if (root)
	{
		node = ft_btree_search_item(root->left, data_ref, cmpf);
		if (cmpf(root->item, data_ref) == 0 && node == 0)
			return (root->item);
		if (node == 0)
			node = ft_btree_search_item(root->right, data_ref, cmpf);
	}
	return (node);
}
