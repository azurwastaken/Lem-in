/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:09:16 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/31 14:04:46 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		fill_adjlist(t_graph *graph, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (j < graph->nb_nodes)
	{
		if (graph->adjacency[i][j] == 2)
			graph->adj_list[i]->link[k++] = j;
		j++;
	}
	graph->adj_list[i]->size = k;
}

int			get_max_path(t_graph *graph)
{
	int link_start;
	int link_end;

	link_start = graph->adj_list[graph->id_start]->size;
	link_end = graph->adj_list[graph->id_end]->size;
	return (link_start > link_end ? link_end : link_start);
}

void		reset_graph(t_graph *graph)
{
	int i;
	int j;

	i = 0;
	while (i < graph->nb_nodes)
	{
		j = 0;
		while (j < graph->nb_nodes)
		{
			if (graph->adjacency[i][j] != 0)
			{
				graph->adjacency[i][j] = 2;
				graph->adjacency[j][i] = 2;
			}
			j++;
		}
		i++;
	}
}

void		free_ways(t_graph *graph)
{
	int i;

	i = 0;
	ft_memdel((void**)&(graph->ways[i]->path[0]));
	ft_memdel((void**)&(graph->ways[i]->path[1]));
	ft_memdel((void**)&(graph->ways[i]->path));
	while (i < get_max_path(graph))
		ft_memdel((void**)&(graph->ways[i++]));
	ft_memdel((void**)&(graph->ways));
}

int			resolve(t_graph *graph, int nb_ant)
{
	int i;

	i = 0;
	if (init_t_way(graph) == EXIT_FAILURE)
		return (0);
	if (!bfs(graph, 0))
		return (EXIT_FAILURE);
	while (bfs(graph, 0))
	{
	}
	reset_graph(graph);
	bfs(graph, 1);
	i++;
	while (bfs(graph, 1))
	{
		if ((graph->ways[i / 2]->size
			+ (nb_ant / i - 1)) < (graph->ways[i]->size)
				&& graph->ways[i - 1]->size != graph->ways[i]->size)
			return (0);
		i++;
	}
	return (0);
}
