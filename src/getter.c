/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:17:31 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/15 18:38:43 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_lstaddnext(t_list **alst, t_list *new)
{
	t_list		*tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

char	*get_name(t_graph *graph, int id)
{
	t_list *list;
	t_node *actual;

	list = graph->lst_nodes;
	while (list)
	{
		actual = (t_node*)list->content;
		if (actual->id == id)
			return (actual->name);
		list = list->next;
	}
	return (0);
}
