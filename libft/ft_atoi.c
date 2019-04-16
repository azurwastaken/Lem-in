/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 11:49:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 12:05:56 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	number;
	int		negative;

	number = 0;
	negative = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == '\t')
		++str;
	if (*str == '-' || *str == '+')
		negative = (*str++ == '-') ? 1 : 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10;
		number = number + *str++ - '0';
	}
	return ((negative) ? (int)number * -1 : (int)number);
}
