/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:00:44 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/23 15:14:45 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H
# include <stdlib.h>
# include "libft/include/libft.h"
# include <stdio.h>

typedef struct		s_node
{
	int				x;
	int				y;
	int				index;
	char			*name;
	struct s_node	*next;
}					t_node;

typedef struct		s_read
{
	char			*line;
	struct s_read	*next;
}					t_read;

typedef struct		s_lem
{
	int				nr_ants;
	int				**map;
	int				n;
	int				*ants;
	int				*parents;
	int				*v;
	char			*line;
	t_node			*start;
	t_node			*end;
	t_node			*list;
	t_node			*arr;
	t_read			*save;
}					t_lem;

/*
** utils.c
*/

void				err(char *str);
int					count_char(char *str, char c);
char				*return_line(void);
void				fill(int *start, int *end, int filler);
void				fill_tab(t_lem	*lem);

/*
** util2.c
*/

void				create_arr(t_lem *lem);
void				create_map(t_lem *lem);
int					get_index(t_lem *lem, char *name);
void				check_duplicates(t_lem *lem);
int					check_ants(int *ants, int nr_ants, int end);

/*
** list_manipulate.c
*/

void				save_line(t_read **save, char *str);
t_node				*create_node(char *str);
void				push_back(t_node **lem, char *str);
int					list_size(t_node *node);

/*
** read_graph.c
*/

void				read_graph(t_lem *lem);
void				get_nr_ants(t_lem *lem);
void				get_links(t_lem *lem);
void				read_nodes(t_lem *lem);
void				check_comments(t_lem *lem);

/*
** solve.c
*/

int					bfs(t_lem *lem, int start);
int					bfs_aux(t_lem *lem, int c[], int bottom, int *top);
void				hex_simulator(t_lem *lem);
void				print_path(t_lem *lem, int ant);
int					next_step(int parents[], int st, int sf);

/*
** lem_in.c
*/

void				hex_simulator_init(t_lem *lem);
int					next_is_not_busy(int *ants, int nr_ants, int next);
void				print_saved_line(t_lem lem);
void				destroy(t_lem *lem);

#endif
