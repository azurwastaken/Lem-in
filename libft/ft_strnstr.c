/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:51:40 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/31 14:10:13 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!*to_find)
		return ((char *)str);
	if (ft_strlen(to_find) > ft_strlen(str))
		return (0);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == to_find[0] && i + j < len)
		{
			j = 0;
			while (str[i + j] == to_find[j] && to_find[j] != '\0'
					&& i + j < len)
				j++;
			if (to_find[j] == '\0')
				return ((char *)(str + i));
			i++;
		}
		else
			i++;
	}
	return (0);
}
