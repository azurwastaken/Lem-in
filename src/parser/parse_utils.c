/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:04:24 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/31 14:04:43 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

t_node	*node_new(int id, char *name)
{
	t_node			*new;

	if (!(new = malloc(sizeof(t_node))))
		return (NULL);
	new->id = id;
	if (!(new->name = ft_strdup((const char*)name)))
		return (NULL);
	new->nb_ants = 0;
	return (new);
}

int		node_add(t_graph *graph, t_node *node)
{
	t_list			*to_add;

	if (!(to_add = ft_lstnew(node, sizeof(t_node))))
		return (1);
	ft_lstadd(&(graph->lst_nodes), to_add);
	graph->nb_nodes++;
	free(node);
	return (0);
}

int		adjacency_new_edge(t_graph *graph, int id_a, int id_b)
{
	if (!graph || (id_a < 0) || (id_a >= graph->nb_nodes)
			|| (id_b < 0) || (id_b >= graph->nb_nodes))
		return (1);
	graph->adjacency[id_a][id_b] = 2;
	graph->adjacency[id_b][id_a] = 2;
	return (0);
}

int		ft_isinteger(char *str)
{
	long long	nb;

	nb = ft_atoll(str);
	return (nb >= INT_MIN && nb <= INT_MAX);
}
