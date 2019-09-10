/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:53:53 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/09 20:01:15 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

char	validate_edge(t_graph *const graph, char **room)
{
	if (ft_arrlen(room, sizeof(void*)) != 2)
		return (0);
	if (!find_room(graph, room[0]) || !find_room(graph, room[1]))
		return (0);
	if (find_edge(graph, room[0], room[1]))
		return (0);
	return (1);
}


void	handle_edges(char *line, t_graph *const graph)
{
	char	**rooms;

	rooms = ft_strsplit(line, '-');
	if (!validate_edge(graph, rooms))
		kill (0);
	if (!add_edge(graph, rooms[0], rooms[1]))
		kill (1);
	ft_strarrdel(rooms);
}