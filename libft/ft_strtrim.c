/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:36:22 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/22 14:46:08 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int begin;
	int end;
	int i;

	if (s == NULL)
		return (NULL);
	begin = 0;
	while (s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
		begin++;
	i = begin;
	end = begin;
	while (s[i] != '\0')
	{
		if ((s[i] != ' ' && s[i] != '\n' && s[i] != '\t'))
			end = i;
		i++;
	}
	return (ft_strsub(s, begin, (end - begin + 1)));
}
