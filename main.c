/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:12:38 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/11 22:41:34 by bvilla           ###   ########.fr       */
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

int		main(void)
{
	char			*line;
	t_graph	*const	graph = graph_init();
	int				n;
	t_map			*edge_to;
	char			*it;

	n = -1;
	while (get_next_line(0, &line) > 0)
	{
		handle_input(line, graph, &n);
	}
	if (!line)
		kill(1);
	if (!(edge_to = edmond(graph)))
		kill(0);

	ft_printf("%s ", graph->t);
	it = graph->t;
	while (map_find_str(edge_to, it))
	{
		it = (*(t_edge**)map_find_str(edge_to, it))->src;
		ft_printf(" <- %s", it);
	}

	return (0);
}
