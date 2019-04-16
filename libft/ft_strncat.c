/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 09:54:51 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/01/26 18:13:51 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t nb)
{
	char *str;

	str = s1;
	while (*s1)
		s1++;
	while (*s2 && nb)
	{
		*s1 = *s2;
		s1++;
		s2++;
		nb--;
	}
	*s1 = '\0';
	return (str);
}