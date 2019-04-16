/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:32:03 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/28 14:32:07 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_bfs(t_graph *graph, t_bfs *bfs)
{
	int i;

	i = 0;
	bfs->queue_size = 1;
	while (i < graph->nb_nodes)
		ft_memdel((void **)&(bfs->visited[i++]));
	ft_memdel((void **)&(bfs->queue));
	ft_memdel((void **)&(bfs->visited));
}

void		fill_way(t_graph *graph, t_bfs *bfs, int id_path)
{
	int i;
	int j;

	i = graph->id_end;
	j = graph->ways[id_path]->size;
	while (bfs->visited[i][1] != -1)
	{
		graph->ways[id_path]->path[0][j] = i;
		i = bfs->visited[i][1];
		j--;
	}
	graph->ways[id_path]->path[0][j] = i;
}

int			add_new_path(t_graph *graph, int id_path, int size)
{
	int j;

	graph->ways[id_path]->size = size;
	if (!(graph->ways[id_path]->path = (int **)malloc(sizeof(int *) * 2)))
		return (EXIT_FAILURE);
	if (!(graph->ways[id_path]->path[0] = (int *)malloc(sizeof(int)
			* (graph->ways[id_path]->size + 1))))
		return (EXIT_FAILURE);
	if (!(graph->ways[id_path]->path[1] = (int *)malloc(sizeof(int)
			* (graph->ways[id_path]->size + 1))))
		return (EXIT_FAILURE);
	j = 0;
	while (j <= graph->ways[id_path]->size)
	{
		graph->ways[id_path]->path[1][j++] = 0;
	}
	return (EXIT_SUCCESS);
}

static void	set_graph(t_graph *graph, int old, int i)
{
	graph->adjacency[old][i] -= 1;
	if (graph->adjacency[old][i] == 1 && graph->adjacency[i][old] == 1)
	{
		graph->adjacency[i][old] = 0;
		graph->adjacency[old][i] = 0;
	}
}

int			get_path(t_graph *graph, t_bfs *bfs, int mode)
{
	static int	id_path = 0;
	int			i;
	int			bubbled;
	int			size;

	i = graph->id_end;
	size = 0;
	bubbled = 0;
	while (bfs->visited[i][1] != -1)
	{
		size++;
		bubbled = 1;
		set_graph(graph, i, bfs->visited[i][1]);
		i = bfs->visited[i][1];
	}
	if (bubbled && mode > 0)
	{
		if (add_new_path(graph, id_path, size) == EXIT_FAILURE)
			return (0);
		fill_way(graph, bfs, id_path);
		graph->nb_way++;
		id_path = mode != 2 ? id_path + 1 : id_path;
	}
	free_bfs(graph, bfs);
	return (bubbled);
}
