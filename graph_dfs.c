/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_dfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:14:26 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/10 16:34:24 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_dfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:14:26 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/10 15:50:36 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	graph_dfs_rec(t_graph *const graph, char *n, t_map *visited, t_map *edge_to)
{
	t_edge	*it;

	map_insert(visited, n, ft_strlen(n) + 1, (void*)1);
	it = *find_room(graph, n);
	(void)edge_to;
	while (it){
		if(!map_find(visited, it->loc, ft_strlen(it->loc) + 1))
		{
			map_insert(edge_to, it->loc, ft_strlen(it->loc) + 1, n);
			graph_dfs_rec(graph, it->loc, visited, edge_to);
		}
		it = it->next;
	}
}

t_map	*graph_dfs(t_graph *const graph)
{
	t_map	*visited;
	t_map	*edge_to;

	visited = map_init(MAP_SIZE);
	edge_to = map_init(MAP_SIZE);
	graph_dfs_rec(graph, graph->s, visited, edge_to);
	map_del(visited);
	if (map_find(edge_to, graph->t, ft_strlen(graph->t) + 1))
		return (edge_to);
	return (NULL);
}