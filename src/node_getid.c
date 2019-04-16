/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_getid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:56:35 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/28 11:56:37 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		node_getid(t_list *lst_nodes, char *name)
{
	t_node			*current_node;

	while (lst_nodes != NULL)
	{
		current_node = (t_node *)lst_nodes->content;
		if (current_node)
		{
			if (ft_strcmp(current_node->name, name) == 0)
				return (current_node->id);
		}
		lst_nodes = lst_nodes->next;
	}
	return (-1);
}
