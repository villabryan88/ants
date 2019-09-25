/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:39:01 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/24 19:35:48 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

char	add_room(t_graph *const graph, char *name)
{
	return map_insert(graph->adj_map, ft_strdup(name), ft_strlen(name) + 1, NULL);
}

t_edge	**find_room(t_graph *const graph, char *name)
{
	return ((t_edge**)map_find(graph->adj_map, name, ft_strlen(name) + 1));
}

void	validate_room(char **room, t_graph *const graph)
{
	if (!ft_strisint(room[1]) || !ft_strisint(room[2]) || room[0][0] == 'L')
		kill(0);
	if (find_room(graph, room[0]))
		kill(0);
}

void	parse_room(char **room, t_graph *const graph){
	if (ft_strequ(SET_ME, graph->s))
		if (!(graph->s = ft_strdup(room[0])))
			kill(1);
	if (ft_strequ(SET_ME, graph->t))
		if (!(graph->t = ft_strdup(room[0])))
			kill(1);
	if (!add_room(graph, room[0]))
		kill(1);
}

void	handle_rooms(char *line, t_graph *const graph, char *rooms_done_flag)
{
	char	**room;

	if (!(room = ft_strsplit(line, ' ')))
		kill(1);
	if (ft_arrlen(room, sizeof(void*)) == 3)
	{
		validate_room(room, graph);
		parse_room(room, graph);
	}
	else if (graph->s && graph->t &&
				!ft_strequ(SET_ME, graph->s) && !ft_strequ(SET_ME, graph->t))
		*rooms_done_flag = 1;
	else
		kill(0);
	ft_strarrdel(room);
}