/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:27:40 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/22 12:53:53 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
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
				del(atm->content, atm->content_size);
			free(atm);
			atm = tmp;
		}
		*alst = NULL;
	}
}
