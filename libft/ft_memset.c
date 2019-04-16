/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:37:12 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/22 14:17:09 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	car;

	i = 0;
	car = (unsigned char)c;
	if (len > 0)
	{
		while (i < len)
		{
			((unsigned char *)b)[i] = car;
			i++;
		}
	}
	return (b);
}
