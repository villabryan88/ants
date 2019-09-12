/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_edmond.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:10:30 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/11 22:24:35 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_map	*edmond_bfs(t_graph *const graph, t_map *taken)
{
	t_map	*visited;
	t_map	*edge_to;
	t_queue	*q;
	t_edge	*it;

	(void)taken;

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

t_map	*edmond(t_graph *const graph)
{
	t_map	*edge_to;
	t_map	*taken;
	char	*dst;

	taken = map_init(MAP_SIZE);
	edge_to = edmond_bfs(graph, taken);
	dst = *map_find_str(edge_to, graph->t);
	while (map_find_str(edge_to, dst))
	{
		if (ft_strequ(dst, graph->s))
			break;
		map_insert_str(taken, dst, (void*)1);
		dst = (char*)*map_find_str(edge_to, dst);
	}



	ft_printf("\nstart: %p\n", map_find_str(taken, "start"));
	ft_printf("1: %p\n", *map_find_str(taken, "1"));
	ft_printf("2: %p\n", *map_find_str(taken, "2"));
	ft_printf("end: %p\n", map_find_str(taken, "end"));
	return edge_to;
}