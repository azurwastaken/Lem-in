/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_by_level.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:05:21 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 11:46:48 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		btree_apply_on_level(t_btree **root, int level,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (*root)
	{
		applyf((*root)->item, level, (level == 1) ? 1 : 0);
		if ((*root)->left)
			btree_apply_on_level(&(*root)->left, level + 1, applyf);
		if ((*root)->right)
			btree_apply_on_level(&(*root)->right, level + 1, applyf);
	}
}

void			ft_btree_apply_by_level(t_btree *root, void (*applyf)(void
			*item, int current_level, int is_first_elem))
{
	btree_apply_on_level(&root, 1, applyf);
}
