/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resolve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:48:41 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/28 14:48:42 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			get_next_id(t_graph *graph, int id)
{
	int i;
	int res;
	int lower;

	i = 0;
	lower = graph->nb_nodes + 2;
	while (i < graph->nb_nodes)
	{
		if (graph->adjacency[id][i] < lower && graph->adjacency[id][i] > 0)
		{
			lower = graph->adjacency[id][i];
			res = i;
		}
		i++;
	}
	return (res + 1);
}

int			init_t_way(t_graph *graph)
{
	int i;

	i = 0;
	graph->nb_way = 0;
	if (!(graph->ways = (t_way **)malloc(sizeof(t_way *)
			* (get_max_path(graph) + 1))))
		return (EXIT_FAILURE);
	while (i < get_max_path(graph))
	{
		if (!(graph->ways[i] = (t_way *)malloc(sizeof(t_way))))
			return (EXIT_FAILURE);
		graph->ways[i]->size = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

void		init_bfs(t_graph *graph, t_bfs *bfs)
{
	int i;

	i = 0;
	bfs->queue_size = 1;
	if (!(bfs->visited = (int **)malloc(sizeof(int *) * graph->nb_nodes)))
		return ;
	if (!(bfs->queue = (int *)malloc(sizeof(int) * graph->nb_nodes)))
		return ;
	while (i < graph->nb_nodes)
	{
		if (!(bfs->visited[i++] = (int *)malloc(sizeof(int) * 2)))
			return ;
	}
}
