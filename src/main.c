/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:17:35 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/31 14:04:48 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	adjacency_put(t_graph *graph)
{
	int	y;
	int	x;

	if (!graph || !graph->adjacency)
		return ;
	y = 0;
	while (y < graph->nb_nodes)
	{
		x = 0;
		while (x < graph->nb_nodes)
		{
			ft_putnbr(graph->adjacency[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int		have_links(t_graph *graph, int id_node)
{
	int i;

	i = 0;
	while (i < graph->nb_nodes)
	{
		if (graph->adjacency[id_node][i] > 0)
			return (1);
		i++;
	}
	return (0);
}

int		links_are_valids(t_graph *graph)
{
	if (graph->adjacency == NULL)
		return (0);
	return (have_links(graph, graph->id_start)
			&& have_links(graph, graph->id_end));
}

int		main(void)
{
	t_env	env;

	if (!init_env(&env))
		return (0);
	if (!parse_stdin(&env))
	{
		if (!links_are_valids(&(env.graph)))
			return (ft_puterror(&env));
		if (create_adj_list(&(env.graph)))
			return (ft_puterror(&env));
		if (resolve(&(env.graph), env.nb_ants) == EXIT_FAILURE)
			return (ft_puterror(&env));
		print_answer(&env);
	}
	else
		return (ft_puterror(&env));
	free_env(&env);
	return (EXIT_SUCCESS);
}
