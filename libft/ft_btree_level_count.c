/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:04:05 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 11:38:56 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_comp_int(int a, int b)
{
	return ((a >= b) ? a : b);
}

static int	ft_size(t_btree *root, int lenght)
{
	if (!root)
		return (lenght);
	else
		return (ft_comp_int(ft_size(root->left, lenght + 1),
					ft_size(root->right, lenght + 1)));
}

int			ft_btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_size(root, 0));
}
