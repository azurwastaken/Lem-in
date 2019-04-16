/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:38:22 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/28 11:38:46 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_lst_free(t_list **alst)
{
	t_list	*atm;
	t_list	*tmp;

	if (*alst)
	{
		atm = *alst;
		while (atm)
		{
			tmp = atm->next;
			if (atm->content)
			{
				ft_strdel(&(((t_node*)(atm->content))->name));
				ft_memdel((void **)&(atm->content));
			}
			free(atm);
			atm = tmp;
		}
		*alst = NULL;
	}
}
