/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:51:39 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/28 11:51:40 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_puterror(t_env *env)
{
	free_error_case(env);
	ft_putstr_fd("ERROR\n", 2);
	return (0);
}

void	free_error_case(t_env *env)
{
	int i;

	ft_lst_free(&(env->graph.lst_nodes));
	i = 0;
	if (env->graph.adjacency)
	{
		while (i < env->graph.nb_nodes)
			ft_memdel((void**)&(env->graph.adjacency[i++]));
		ft_memdel((void **)&(env->graph.adjacency));
	}
	i = 0;
	if (env->graph.adj_list)
	{
		while (i < env->graph.nb_nodes)
		{
			ft_memdel((void**)&(env->graph.adj_list[i]->link));
			ft_memdel((void**)&(env->graph.adj_list[i++]));
		}
		ft_memdel((void**)&(env->graph.adj_list));
	}
	if (env->graph.ways && !env->graph.ways[0]->size)
	{
		ft_memdel((void**)&(env->graph.ways[0]));
		ft_memdel((void **)&(env->graph.ways));
	}
}
