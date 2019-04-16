/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:59:22 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/28 11:59:23 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	right_pad_path(t_graph *graph, int id)
{
	int i;

	i = graph->ways[id]->size - 1;
	while (i >= 0)
	{
		if (graph->ways[id]->path[1][i] > 0)
		{
			print_move(graph, graph->ways[id]->path[1][i],
			graph->ways[id]->path[0][i + 1]);
			graph->is_firstinstr = 0;
			graph->ways[id]->path[1][i + 1] = graph->ways[id]->path[1][i];
			graph->ways[id]->path[1][i] = 0;
		}
		i--;
	}
}

void	put_ants(int id_ant, t_graph *graph, int id_path)
{
	graph->ways[id_path]->path[1][1] = id_ant;
	print_move(graph, id_ant, graph->ways[id_path]->path[0][1]);
	graph->is_firstinstr = 0;
}

int		path_are_empty(t_graph *graph)
{
	int i;
	int j;

	i = 0;
	while (i < graph->nb_way)
	{
		j = 0;
		while (j < graph->ways[i]->size)
		{
			if (graph->ways[i]->path[1][j] > 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	empty(t_graph *graph)
{
	int i;

	while (path_are_empty(graph))
	{
		graph->is_firstinstr = 1;
		i = 0;
		while (i < graph->nb_way)
		{
			right_pad_path(graph, i);
			i++;
		}
		ft_putstr("\n");
	}
}

int		print_answer(t_env *env)
{
	int curr_ant;
	int i;
	int usenpath;

	curr_ant = 1;
	ft_putstr("\n");
	if (!(usenpath = path_to_use(&(env->graph), env->nb_ants - curr_ant)))
		return (EXIT_FAILURE);
	while (curr_ant <= env->nb_ants)
	{
		env->graph.is_firstinstr = 1;
		i = 0;
		while (i < get_max_path(&(env->graph)))
			right_pad_path(&(env->graph), i++);
		i = 0;
		while (i < usenpath && curr_ant <= env->nb_ants)
		{
			put_ants(curr_ant++, &(env->graph), i++);
			usenpath = path_to_use(&(env->graph), env->nb_ants - curr_ant);
		}
		ft_putstr("\n");
	}
	empty(&(env->graph));
	return (EXIT_SUCCESS);
}
