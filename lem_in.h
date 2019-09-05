/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:09:29 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/05 15:59:58 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <libft.h>
# include <stdlib.h>

typedef struct	s_map {
	t_list		**map;
	int			size;
}				t_map; 

typedef struct	s_graph {
	t_map		*map;
	char		*s;
	char		*t;
}				t_graph;

typedef struct	s_edge {
	char		*loc;
	char		taken;
}				t_edge;

t_map			*map_init(void);
#endif