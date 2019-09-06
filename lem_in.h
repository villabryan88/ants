/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:09:29 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/05 22:53:48 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_map {
	t_list		**map;
	int			size;
}				t_map; 

typedef struct	s_graph {
	t_map		*adj_map;
	char		*s;
	char		*t;
}				t_graph;

typedef struct	s_edge {
	char		*loc;
	char		taken;
}				t_edge;

t_map			*map_init(void);
void			kill(char print);
void			**map_find(t_map *map, char *key);
void			map_insert(t_map *adj_map, char *key, void *val);
void			add_graph_node(t_graph *graph, char *key);
#endif