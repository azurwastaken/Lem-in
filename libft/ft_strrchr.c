/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:12:57 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 12:04:19 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		res;

	i = 0;
	res = -1;
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			res = i;
		i++;
	}
	if (res == -1)
		return (0);
	return (&((char *)s)[res]);
}
