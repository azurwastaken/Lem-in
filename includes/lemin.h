/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:17:52 by mcaseaux          #+#    #+#             */
/*   Updated: 2019/01/30 17:54:53 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef struct			s_bfs
{
	int					**visited;
	int					*queue;
	int					queue_size;
}						t_bfs;

typedef struct			s_node
{
	int					id;
	char				*name;
	int					nb_ants;
}						t_node;

typedef struct			s_way
{
	int					**path;
	int					size;
}						t_way;

typedef	struct			s_adjlist
{
	int					*link;
	int					size;
}						t_adjlist;

typedef struct			s_graph
{
	int					nb_nodes;
	t_list				*lst_nodes;
	int					**adjacency;
	t_adjlist			**adj_list;
	int					id_start;
	int					id_end;
	t_way				**ways;
	int					nb_way;
	int					is_firstinstr;
}						t_graph;

typedef struct			s_env
{
	int					nb_ants;
	t_graph				graph;
}						t_env;

typedef struct			s_parser
{
	int					number_of_ants_found;
	int					adjacency_created;
	int					next_is_start;
	int					next_is_end;
}						t_parser;

int						line_handle(t_env *env, t_parser *parser, char *line);

int						line_iscomment(char *line);
int						line_iscommand(char *line);
int						line_isnode(char *line);
int						*line_isedge(t_list *lst_nodes, char *line);

long long				ft_atoll(const char *str);
void					parser_init(t_parser *parser);
int						parse_stdin(t_env *env);

int						is_whitespace(char c);
int						node_add(t_graph *graph, t_node *node);
t_node					*node_new(int id, char *name);
int						adjacency_new_edge(t_graph *graph, int id_a, int id_b);
int						ft_isinteger(char *str);

void					queue_pull(t_bfs *bfs);
void					iterative_bfs(t_graph *graph, int currid, t_bfs *bfs);
int						bfs(t_graph *graph, int mode);

int						ft_puterror(t_env *env);
int						ft_puterror_free(t_env *env);
void					free_error_case(t_env *env);

void					free_bfs(t_graph *graph, t_bfs *bfs);
void					fill_way(t_graph *graph, t_bfs *bfs, int id_path);
int						add_new_path(t_graph *graph, int id_path, int size);
int						get_path(t_graph *graph, t_bfs *bfs, int mode);

void					ft_lstaddnext(t_list **alst, t_list *new);
char					*get_name(t_graph *graph, int id);

void					free_env(t_env *env);
int						graph_init(t_graph *graph);
int						init_env(t_env *env);
int						create_adj_list(t_graph *graph);

int						get_next_id(t_graph *graph, int id);
int						init_t_way(t_graph *graph);
void					init_bfs(t_graph *graph, t_bfs *bfs);

void					ft_lst_free(t_list **alst);

int						node_getid(t_list *lst_nodes, char *name);

int						is_int(char c);
int						is_alnum(char c);
void					ft_lststrput(t_list *begin_list);
void					ft_intarr_put(int *arr, int len);

int						resolve(t_graph *graph, int nb_ant);
int						get_max_path(t_graph *graph);
void					fill_adjlist(t_graph *graph, int i);

int						print_answer(t_env *env);

void					print_move(t_graph *graph, int id_ant, int id_room);
int						path_to_use(t_graph *graph, int nb_ants);

#endif
