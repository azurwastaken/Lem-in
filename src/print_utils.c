/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:05:04 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/30 17:05:55 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_move(t_graph *graph, int id_ant, int id_room)
{
	if (graph->is_firstinstr == 0)
		ft_putstr(" ");
	ft_putstr("L");
	ft_putnbr(id_ant);
	ft_putstr("-");
	ft_putstr(get_name(graph, id_room));
}

int		path_to_use(t_graph *graph, int nb_ants)
{
	int i;

	i = 1;
	while (i < graph->nb_way)
	{
		if ((graph->ways[i / 2 + 1]->size
			+ (nb_ants / i - 1)) < (graph->ways[i]->size)
				&& graph->ways[i - 1]->size != graph->ways[i]->size)
			return (i);
		i++;
	}
	return (i);
}
