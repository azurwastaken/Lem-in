/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:44:38 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/22 12:56:10 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*beginlist;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(newlst = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	beginlist = newlst;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(newlst->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		newlst = newlst->next;
	}
	return (beginlist);
}
