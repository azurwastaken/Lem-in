/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:48:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 11:51:00 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_countsplit(const char *str, char c)
{
	size_t		count;
	int			inword;

	inword = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (inword && *str == c)
			inword = 0;
		if (!inword && *str != c)
		{
			count++;
			inword = 1;
		}
		str++;
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	count;
	size_t	l;
	size_t	k;
	char	**array;

	count = ft_countsplit(s, c);
	if (!(array = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	l = 0;
	while (count--)
	{
		k = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			k++;
			s++;
		}
		if (!(array[l] = ft_strsub((const char *)(s - k), 0, k)))
			return (NULL);
		l++;
	}
	array[l] = 0;
	return (array);
}
