/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:54:34 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/11 21:03:27 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_graph	*graph_init(void)
{
	t_graph	*new;

	new = malloc(sizeof(t_graph));
	new->adj_map = map_init(MAP_SIZE);
	new->s = NULL;
	new->t = NULL;
	return (new);
}

t_edge	*edge_init(char *loc)
{
	t_edge	*new;
	char	*copy;
	
	if (!(new = malloc(sizeof(t_edge))) || !(copy = ft_strdup(loc)))
		return (NULL);
	new->loc = copy;
	new->taken = 0;
	new->rev = NULL;
	new->next = NULL;
	return (new);
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

char	add_edge(t_graph *const graph, char *room1, char *room2)
{
	t_edge	*forward;
	t_edge	*reverse;
	t_edge	**edge_list;

	forward = edge_init(room2);
	reverse = edge_init(room1);
	forward->rev = reverse;
	reverse->rev = forward;
	if (!forward || !reverse)
		return (0);
	edge_list = find_room(graph, room1);
	forward->next = *edge_list;
	*edge_list = forward;
	edge_list = find_room(graph, room2);
	reverse->next = *edge_list;
	*edge_list = reverse;
	return (1);
}