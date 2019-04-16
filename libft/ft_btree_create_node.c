/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:58:03 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/22 15:00:56 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree *node;

	if (!(node = malloc(sizeof(t_btree))))
		return (0);
	node->item = item;
	node->left = 0;
	node->right = 0;
	return (node);
}
