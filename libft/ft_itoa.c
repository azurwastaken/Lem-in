/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:35:29 by exam              #+#    #+#             */
/*   Updated: 2017/11/22 14:43:03 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digit(int nbr)
{
	int		len;
	long	nb;

	len = 0;
	if (nbr < 0)
		len = len + 1;
	nb = nbr < 0 ? (long)nbr * -1 : nbr;
	while (nb != 0)
	{
		nb = nb / 10;
		len = len + 1;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	i = ft_count_digit(n) - 1;
	if (!(str = malloc(sizeof(char) * (ft_count_digit(n) + 1))))
		return (NULL);
	nb = n < 0 ? (long)n * -1 : n;
	while (nb != 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (i == 0)
		str[i] = '-';
	str[ft_count_digit(n)] = '\0';
	return (str);
}
