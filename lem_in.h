/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:09:29 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/06 12:52:05 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
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
#endif