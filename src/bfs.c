/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:48:15 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/30 17:18:12 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		queue_pull(t_bfs *bfs)
{
	int i;

	i = 0;
	while (i < bfs->queue_size)
	{
		bfs->queue[i] = bfs->queue[i + 1];
		i++;
	}
	bfs->queue_size--;
}

void		iterative_bfs(t_graph *graph, int currid, t_bfs *bfs)
{
	int i;

	while (bfs->queue_size > 0)
	{
		i = 0;
		while (i < graph->adj_list[currid]->size)
		{
			if (graph->adjacency[graph->adj_list[currid]->link[i]][currid] > 1
					&& !bfs->visited[graph->adj_list[currid]->link[i]][0])
			{
				bfs->queue[bfs->queue_size] = graph->adj_list[currid]->link[i];
				bfs->queue_size++;
				bfs->visited[graph->adj_list[currid]->link[i]][0] = 1;
				bfs->visited[graph->adj_list[currid]->link[i]][1] = currid;
			}
			i++;
		}
		queue_pull(bfs);
		currid = bfs->queue[0];
	}
}

int			bfs(t_graph *graph, int mode)
{
	t_bfs	bfs;
	int		i;

	init_bfs(graph, &bfs);
	i = 0;
	while (i < graph->nb_nodes)
	{
		bfs.visited[i][1] = -1;
		bfs.visited[i++][0] = 0;
	}
	bfs.visited[graph->id_start][0] = 1;
	iterative_bfs(graph, graph->id_start, &bfs);
	return (get_path(graph, &bfs, mode));
}
