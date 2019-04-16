/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 09:11:04 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 12:02:31 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *restrict s2)
{
	char *str;

	str = s1;
	while (*s1)
		s1++;
	ft_strcpy(s1, s2);
	return (str);
}
