/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:53:53 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/09 19:30:57 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_edge	*edge_init(char *loc)
{
	t_edge	*new;
	char	*copy;
	
	if (!(new = malloc(sizeof(t_edge))) || !(copy = ft_strdup(loc)))
		return (NULL);
	new->loc = copy;
	new->taken = 0;
	new->next = NULL;
	return (new);
}

char	add_edge(t_graph *const graph, char *room1, char *room2)
{
	t_edge	*forward;
	t_edge	*reverse;
	t_edge	**edge_list;

	forward = edge_init(room2);
	reverse = edge_init(room1);
	if (!forward || !reverse)
		kill(1);
	edge_list = find_room(graph, room1);
	forward->next = *edge_list;
	*edge_list = forward;
	edge_list = find_room(graph, room2);
	reverse->next = *edge_list;
	*edge_list = reverse;
}

t_edge	*find_edge(t_graph *const graph, char *src_room, char *dst_room)
{
	t_edge	*list;

	list = *find_room(graph, src_room);
	while (list){
		if (ft_strequ(list->loc, dst_room))
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	validate_edge(t_graph *const graph, char **room)
{
	if (!ft_arrlen(room, sizeof(void*)) == 2)
		kill(0);
	if (!find_room(graph->adj_map, room[0]) || !find_room(graph->adj_map, room[1]))
		kill(0);
	if (find_edge(graph, room[0], room[1]))
		kill(0);

}


void	handle_edges(char *line, t_graph *const graph)
{
	char	**rooms;

	rooms = ft_strsplit(line, '-');
	validate_edge(graph, rooms);
	add_edge(graph, rooms[0], rooms[1]);
	ft_strarrdel(rooms);
}