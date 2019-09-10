/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:12:38 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/10 16:41:48 by bvilla           ###   ########.fr       */
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
	t_map			*tmp;
	char			*it;

	n = -1;
	while (get_next_line(0, &line) > 0)
	{
		handle_input(line, graph, &n);
	}
	if (!line)
		kill(1);
	if (!(tmp = graph_dfs(graph)))
		kill(0);
	it = graph->t;
	ft_printf("%s ", graph->t);
	while (map_find(tmp, it, ft_strlen(it) + 1))
	{
		ft_printf(" <- %s", (char*)*map_find(tmp, it, ft_strlen(it) + 1));
		it = (char*)*map_find(tmp, it, ft_strlen(it) + 1);
	}
	return (0);
}
