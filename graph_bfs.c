/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:35:43 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/24 20:02:57 by bvilla           ###   ########.fr       */
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
	map_insert_str(visited, (char*)q_peek(q), (void*)1);
	while (!it && !q_isempty(q))
	{
		it = *find_room(graph, (char*)q_peek(q));
		while (it)
		{
			if(!map_find_str(visited, it->dst))
			{
				q_push(q, it->dst);
				map_insert_str(edge_to, it->dst, q_peek(q));
				map_insert_str(visited, it->dst, (void*)1);
				if (ft_strequ((char*)q_peek(q), it->dst))
					break;
			}
			it = it->next;
		}
		q_pop(q);
	}
	map_del(visited);
	if (map_find(edge_to, graph->t, ft_strlen(graph->t) + 1))
		return (edge_to);
	return (NULL);
}
t_map	*graph_bfs_taken(t_graph *const graph, char *src, char *dst)
{
	t_map	*visited;
	t_map	*edge_to;
	t_queue	*q;
	t_edge	*it;

	it = NULL;
	q = q_init();
	visited = map_init(MAP_SIZE);
	edge_to = map_init(MAP_SIZE);
	q_push(q, src);
	map_insert_str(visited, (char*)q_peek(q), (void*)1);
	while (!it && !q_isempty(q))
	{
		it = *find_room(graph, (char*)q_peek(q));
		while (it)
		{
			if(!map_find_str(visited, it->dst) && it->taken)
			{
				q_push(q, it->dst);
				map_insert_str(edge_to, it->dst, it);
				map_insert_str(visited, it->dst, (void*)1);
				if (ft_strequ((char*)q_peek(q), dst))
					break;
			}
			it = it->next;
		}
		q_pop(q);
	}
	free(q);
	map_del(visited);
	if (map_find_str(edge_to, dst))
		return (edge_to);
	map_del(edge_to);
	return (NULL);
}