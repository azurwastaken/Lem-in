/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhercha <akhercha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:14:14 by akhercha          #+#    #+#             */
/*   Updated: 2019/01/31 14:04:37 by akhercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

long long			ft_atoll(const char *str)
{
	unsigned long long	nbr;
	int					neg;

	while (is_whitespace(*str))
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else
	{
		neg = 0;
		if (*str == '+')
			str++;
	}
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (neg) ? -(long long)nbr : (long long)nbr;
}

static int			ft_isnumber(char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_isdigit((int)str[i]))
			|| ((i == 0) && ((str[i] == '-') || (str[i] == '+'))))
			i++;
		else
			return (0);
	}
	return (1);
}

void				parser_init(t_parser *parser)
{
	parser->number_of_ants_found = 0;
	parser->adjacency_created = 0;
	parser->next_is_start = 0;
	parser->next_is_end = 0;
}

static int			line_get_ants(t_env *env)
{
	char		*line;
	int			ants_from_file;

	if (get_next_line(0, &line))
	{
		while (line_iscomment(line) || line_iscommand(line) == 3)
		{
			ft_putendl(line);
			ft_strdel(&line);
			get_next_line(0, &line);
		}
		if (ft_isnumber(line) && ft_isinteger(line))
		{
			ants_from_file = ft_atoi(line);
			env->nb_ants = ants_from_file;
		}
		else
			exit(ft_puterror(env));
	}
	else
		exit(ft_puterror(env));
	if (env->nb_ants > 0)
		ft_putendl(line);
	ft_strdel(&line);
	return (env->nb_ants <= 0);
}

int					parse_stdin(t_env *env)
{
	char		*line;
	t_parser	parser;

	parser_init(&parser);
	if (line_get_ants(env) == 1)
		return (1);
	while (get_next_line(0, &line))
	{
		if (!line || !*line || (line_handle(env, &parser, line) == 1))
		{
			ft_strdel(&line);
			return (1);
		}
		ft_putendl(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
