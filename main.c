/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:12:38 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/09 19:00:30 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#define MAP_SIZE 40000

void	kill(char print)
{
	ft_printf("ERROR\n");
	if (print)
		perror(NULL);
	exit(0);
}

t_graph	*graph_init(void)
{
	t_graph	*new;

	new = malloc(sizeof(t_graph));
	new->adj_map = map_init(MAP_SIZE);
	new->s = NULL;
	new->t = NULL;
	return (new);
}




void	handle_ants(char *line, int *n)
{
	if (!ft_strisint(line))
		kill(1);
	if (ft_atoi(line) < 0)
		kill(0);
	*n = ft_atoi(line);
}

char	parse_command(char *line, t_graph *const graph, char rooms_done_flag)
{
	char	**to_set;

	if (rooms_done_flag)
		return (0);
	if (ft_strequ("##start", line))
		to_set = &graph->s;
	else if (ft_strequ("##end", line))
		to_set = &graph->t;
	else
		return (0);
	if (*to_set)
		return (0);
	*to_set = SET_ME;	
	return (1);
}

void	set_check_command_flag(char *line, t_graph *graph, char rooms_done_flag)
{

	if (ft_strnequ("##", line, 2))
	{
		if (!parse_command(line, graph, rooms_done_flag))
			kill(0);
	}
	else
	{
		if (ft_strequ(graph->s, SET_ME) || ft_strequ(graph->t, SET_ME))
			kill(0);
	}
}

void	parse_check_print_input(char *line, t_graph *const graph, int *n)
{
	char	rooms_done_flag;

	rooms_done_flag = 0;
	if (*n == -1)
		handle_ants(line, n);
	else if (ft_strnequ("#", line, 1))
		set_check_command_flag(line, graph, rooms_done_flag);
	else
	{
		if (!rooms_done_flag)
			handle_rooms(line, graph, &rooms_done_flag);
		if (rooms_done_flag)
			handle_edges(line, graph);
	}
	if (!ft_strnequ("#", line, 1) || ft_strnequ("##", line, 2))
		ft_printf("%s\n", line);
}

int		main(void)
{
	char			*line;
	t_graph	*const	graph = graph_init();
	int				n;

	n = -1;
	while (get_next_line(0, &line) > 0)
	{
		parse_check_print_input(line, graph, &n);
	}
	if (!line)
		kill(1);
	return (0);
}
