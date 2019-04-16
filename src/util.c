/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:17:08 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/28 14:48:27 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_int(char c)
{
	return (c >= '0' && c <= '9');
}

int		is_alnum(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}

void	ft_intarr_put(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(arr[i]);
		if (i < len - 1)
			ft_putstr(", ");
		i++;
	}
}

void	ft_lststrput(t_list *begin_list)
{
	t_list	*tmp;
	t_node	*curr;

	tmp = begin_list;
	while (tmp)
	{
		curr = (t_node *)tmp->content;
		ft_putendl(curr->name);
		tmp = tmp->next;
	}
}
