/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:05:52 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/01/26 16:43:14 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*from;
	char	*to;

	from = (char*)src;
	to = (char*)dest;
	if (from < to)
	{
		from = (from + n) - 1;
		to = (to + n) - 1;
		while (n-- > 0)
			*to-- = *from--;
	}
	else
	{
		while (n-- > 0)
			*to++ = *from++;
	}
	return (dest);
}
