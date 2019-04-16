/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:53:28 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 11:59:58 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *mem_alloc;

	if (!(mem_alloc = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1))))
		return (0);
	mem_alloc = ft_strcpy(mem_alloc, src);
	return (mem_alloc);
}
