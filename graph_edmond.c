/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_edmond.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:10:30 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/12 20:13:52 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_map	*edmond_bfs(t_graph *const graph, t_map *node_taken)
{
	t_map	*visited;
	t_map	*edge_to;
	t_queue	*q;
	t_edge	*it;

	(void)node_taken;

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
				map_insert_str(edge_to, it->dst, it);
				map_insert_str(visited, it->dst, (void*)1);
				if (ft_strequ((char*)q_peek(q), it->dst))
					break;
			}
			it = it->next;
		}
		q_pop(q);
	}
	map_del(visited);
	if (map_find_str(edge_to, graph->t))
		return (edge_to);
	return (NULL);
}

void	process_taken_subpath(t_queue *q, t_map *taken)
{
	q_pop(q);
	q_pop(q);
	while (!q_isempty(q))
		*map_find_str(taken, ((t_edge*)q_pop(q))->dst) = 0;
}

void	process_path(t_graph *const graph, t_map *edge_to, t_map *node_taken)
{
	t_edge	*it;
	t_queue	*q;

	q = q_init();
	it = *map_find_str(edge_to, graph->t);
	while (it)
	{
		it->taken = 1;
		it->rev->taken = 0;
		if (ft_strequ(it->src, graph->s))
			break;
		if (!map_find_str(node_taken, it->src))
			map_insert_str(node_taken, it->src, (void*)0);
		if (*map_find_str(node_taken, it->src))
			q_push(q, it);
		else
		{
			*map_find_str(node_taken, it->src) = (void*)1;
			if (!q_isempty(q))
				process_taken_subpath(q, node_taken);
		}
		it = *map_find_str(edge_to, it->src);
	}
}

t_map	*edmond(t_graph *const graph)
{
	t_map	*edge_to;
	t_map	*node_taken;

	node_taken = map_init(MAP_SIZE);
	edge_to = edmond_bfs(graph, node_taken);
	process_path(graph, edge_to, node_taken);



	ft_printf("\nstart: %p\n", map_find_str(node_taken, "start"));
	ft_printf("1: %p\n", *map_find_str(node_taken, "1"));
	ft_printf("2: %p\n", *map_find_str(node_taken, "2"));
	ft_printf("end: %p\n", map_find_str(node_taken, "end"));
	return edge_to;
}