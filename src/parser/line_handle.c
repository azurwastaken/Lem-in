/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:14:14 by akhercha          #+#    #+#             */
/*   Updated: 2019/01/31 14:04:36 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			adjacency_init(t_graph *graph)
{
	int		y;
	int		x;

	if (!(graph->nb_nodes > 1 && graph->id_start >= 0 && graph->id_end >= 0))
		return (1);
	if (!(graph->adjacency = malloc(sizeof(int*) * graph->nb_nodes)))
		return (1);
	y = 0;
	while (y < graph->nb_nodes)
	{
		if (!(graph->adjacency[y] = malloc(sizeof(int) * graph->nb_nodes)))
			return (1);
		x = 0;
		while (x < graph->nb_nodes)
			graph->adjacency[y][x++] = 0;
		y++;
	}
	return (0);
}

static int			handle_command(t_parser *parser, int command_code)
{
	if (command_code <= 0)
		return (1);
	else if (command_code == 1)
	{
		parser->next_is_end = 0;
		parser->next_is_start = 1;
	}
	else if (command_code == 2)
	{
		parser->next_is_start = 0;
		parser->next_is_end = 1;
	}
	return (0);
}

static int			handle_node(t_env *env, t_parser *parser, char *line,
	int pos_space)
{
	char		*node_name;
	int			existing_id;

	node_name = ft_strsub(line, 0, pos_space);
	existing_id = node_getid((env->graph).lst_nodes, node_name);
	if (existing_id == -1)
	{
		node_add(&env->graph, node_new((env->graph).nb_nodes, node_name));
		if (parser->next_is_start)
		{
			(env->graph).id_start = (env->graph).nb_nodes - 1;
			parser->next_is_start = 0;
		}
		else if (parser->next_is_end)
		{
			(env->graph).id_end = (env->graph).nb_nodes - 1;
			parser->next_is_end = 0;
		}
	}
	ft_strdel(&node_name);
	return (existing_id == -1 ? 0 : 1);
}

static int			handle_edge(t_graph *graph, int **ids)
{
	if (!ids)
		return (1);
	adjacency_new_edge(graph, (*ids)[0], (*ids)[1]);
	free(*ids);
	*ids = NULL;
	return (0);
}

int					line_handle(t_env *env, t_parser *parser, char *line)
{
	int		*ids;
	int		ret;

	if (line_iscomment(line))
		return (0);
	else if ((ret = line_iscommand(line)) > 0)
		return (handle_command(parser, ret));
	else if ((ret = line_isnode(line)) > 0 && !parser->adjacency_created)
		return (handle_node(env, parser, line, ret));
	else if (!parser->adjacency_created)
	{
		if (adjacency_init(&(env->graph)) == 1)
			return (1);
		parser->adjacency_created = 1;
	}
	if ((ids = line_isedge((env->graph).lst_nodes, line)) != NULL)
		return (handle_edge(&(env->graph), &ids));
	return (1);
}
