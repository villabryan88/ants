/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:12:38 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/24 20:04:05 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	kill(char print)
{
	ft_printf("ERROR\n");
	if (print)
		perror(NULL);
	exit(0);
}
void	print_path(t_map *edge_to, char *src, char *dst)
{
	char *it;
	t_stack *stack;

	stack = stack_init();
	it = dst;
	while (!ft_strequ(src, it))
	{
		stack_push(stack, it);
		it = (*(t_edge**)map_find_str(edge_to, it))->src;
	}
	ft_printf("%s ", src);
	while (!stack_isempty(stack))
		ft_printf("-> %s ", stack_pop(stack));
	free(stack);
}

void	print_paths(t_graph *const graph)
{
	t_edge	*it;
	t_queue	*q;
	t_map	*edge_to;
	char	*head;

	q = q_init();
	it = *find_room(graph, graph->s);
	while(it)
	{
		if (it->taken)
			q_push(q, it->dst);
		it = it->next;
	}
	while(!q_isempty(q))
	{
		ft_printf("%s -> ", graph->s);
		head = q_pop(q);
		edge_to = graph_bfs_taken(graph, head, graph->t);
		print_path(edge_to, head, graph->t);
		ft_printf("\n");
		map_del(edge_to);
	}
	free(q);
}

int		main(void)
{
	char			*line;
	t_graph	*const	graph = graph_init();
	int				n;
	t_map			*edge_to;

	n = -1;
	while (get_next_line(0, &line) > 0)
	{
		handle_input(line, graph, &n);
		free(line);
	}
	if (!line)
		kill(1);
	if (!(edge_to = edmond(graph)))
		kill(0);

	print_paths(graph);
	while(1);
	return (0);
}
