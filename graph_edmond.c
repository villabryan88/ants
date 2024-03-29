/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_edmond.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:10:30 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/24 19:54:51 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

char	is_node_taken(t_map *node_taken, char *key)
{
	return (map_find_str(node_taken, key) && *map_find_str(node_taken, key));
}

t_map	*edmond_bfs(t_graph *const graph, t_map *node_taken,
											char *src, char *dst)
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
	q_push(q, src);
	map_insert_str(visited, (char*)q_peek(q), (void*)1);
	while (!it && !q_isempty(q))
	{
		it = *find_room(graph, (char*)q_peek(q));
		while (it)
		{
			if(!map_find_str(visited, it->dst) && !it->taken)
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
	free(q);
}
t_map	*edmond(t_graph *const graph)
{
	t_map	*edge_to;
	t_map	*node_taken;

	node_taken = map_init(MAP_SIZE);
	edge_to = edmond_bfs(graph, node_taken, graph->s, graph->t);
	process_path(graph, edge_to, node_taken);
	map_del(edge_to);
	edge_to = edmond_bfs(graph, node_taken, graph->s, graph->t);
	process_path(graph, edge_to, node_taken);


	ft_printf("\nstart: %p\n", map_find_str(node_taken, "start"));
	ft_printf("1: %p\n", *map_find_str(node_taken, "1"));
	ft_printf("2: %p\n", *map_find_str(node_taken, "2"));
	ft_printf("end: %p\n", map_find_str(node_taken, "end"));
	map_del(node_taken);
	return edge_to;
}