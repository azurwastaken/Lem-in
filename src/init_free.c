/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:51:44 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/31 14:04:45 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_adj_list(t_graph *graph)
{
	int	i;

	i = 0;
	if (!(graph->adj_list = (t_adjlist **)malloc(sizeof(t_adjlist*)
			* graph->nb_nodes)))
		return (EXIT_FAILURE);
	while (i < graph->nb_nodes)
	{
		if (!(graph->adj_list[i] = (t_adjlist *)malloc(sizeof(t_adjlist)
				* graph->nb_nodes)))
			return (EXIT_FAILURE);
		if (!(graph->adj_list[i]->link = malloc(sizeof(int) * graph->nb_nodes)))
			return (EXIT_FAILURE);
		fill_adjlist(graph, i);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	free_adjlist(t_env *env)
{
	int i;

	i = 0;
	while (i < env->graph.nb_nodes)
	{
		ft_memdel((void**)&(env->graph.adj_list[i]->link));
		ft_memdel((void**)&(env->graph.adj_list[i]));
		i++;
	}
}

void	free_env(t_env *env)
{
	int i;

	ft_lst_free(&(env->graph.lst_nodes));
	i = 0;
	while (i < get_max_path(&(env->graph)))
	{
		if (env->graph.ways[i]->size > 0)
		{
			ft_memdel((void**)&(env->graph.ways[i]->path[0]));
			ft_memdel((void**)&(env->graph.ways[i]->path[1]));
			ft_memdel((void**)&(env->graph.ways[i]->path));
		}
		ft_memdel((void**)&(env->graph.ways[i]));
		i++;
	}
	ft_memdel((void **)&(env->graph.ways));
	i = 0;
	while (i < env->graph.nb_nodes)
		ft_memdel((void**)&(env->graph.adjacency[i++]));
	ft_memdel((void **)&(env->graph.adjacency));
	free_adjlist(env);
	ft_memdel((void**)&(env->graph.adj_list));
}

int		graph_init(t_graph *graph)
{
	graph->nb_nodes = 0;
	graph->adjacency = NULL;
	graph->id_start = -1;
	graph->id_end = -1;
	graph->adj_list = NULL;
	return (0);
}

int		init_env(t_env *env)
{
	env->nb_ants = -1;
	if (!(env->graph.lst_nodes = ft_lstnew(NULL, 0)))
		return (1);
	env->graph.adjacency = NULL;
	env->graph.nb_nodes = 0;
	env->graph.id_start = -1;
	env->graph.id_end = -1;
	env->graph.ways = NULL;
	env->graph.adj_list = NULL;
	return (1);
}
