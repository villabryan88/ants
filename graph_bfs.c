/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:35:43 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/11 20:47:03 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <lem_in.h>

t_map	*graph_bfs(t_graph *const graph)
{
	t_map	*visited;
	t_map	*edge_to;
	t_queue	*q;
	t_edge	*it;

	it = NULL;
	q = q_init();
	visited = map_init(MAP_SIZE);
	edge_to = map_init(MAP_SIZE);
	q_push(q, graph->s);
	while (!it && !q_isempty(q))
	{
		map_insert_str(visited, (char*)q_peek(q), (void*)1);
		it = *find_room(graph, (char*)q_peek(q));
		while (it)
		{
			if(!map_find_str(visited, it->loc))
			{
				q_push(q, it->loc);
				map_insert_str(edge_to, it->loc, q_peek(q));
				if (ft_srequ((char*)q_peek(q), it->loc))
					break;
			}
			it = it->next;
		}
		q_pop(q);
	}
	map_del(visited);
	return (edge_to);
}