/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:09:29 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/10 16:23:51 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define SET_ME "#set_me"
# define MAP_SIZE 40000
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_graph {
	t_map			*adj_map;
	char			*s;
	char			*t;
}					t_graph;

typedef struct		s_edge {
	char			*loc;
	char			taken;
	struct s_edge 	*next;
}					t_edge;

void				kill(char print);
void				add_graph_node(t_graph *graph, char *key);
void				handle_rooms(char *line, t_graph *const graph, char *rooms_done_flag);
void				validate_room(char **room, t_graph *const graph);
void				parse_room(char**room, t_graph *const graph);
t_edge				**find_room(t_graph *const graph, char *name);
void				handle_edges(char *line, t_graph *const graph);
t_graph				*graph_init(void);
t_edge				*edge_init(char *loc);
t_edge				**find_room(t_graph *const graph, char *name);
t_edge				*find_edge(t_graph *const graph, char *src_room, char *dst_room);
char				add_edge(t_graph *const graph, char *room1, char *room2);
char				set_chk_cmd_flag(char *line, t_graph *const graph, char rooms_done_flag);
void				handle_ants(char *line, int *n);
void				handle_cmd_comments(char *line, t_graph *graph, char rooms_done_flag);
char				set_chk_cmd_flag(char *line, t_graph *const graph, char rooms_done_flag);
void				handle_input(char *line, t_graph *const graph, int *n);
t_map				*graph_dfs(t_graph *const graph);
#endif