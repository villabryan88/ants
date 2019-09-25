/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:05:56 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/24 19:38:23 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	handle_input(char *line, t_graph *const graph, int *n)
{
	char	rooms_done_flag;

	rooms_done_flag = 0;
	if (*n == -1)
		handle_ants(line, n);
	else if (ft_strnequ("#", line, 1))
		handle_cmd_comments(line, graph, rooms_done_flag);
	else
	{
		if (!rooms_done_flag)
			handle_rooms(line, graph, &rooms_done_flag);
		if (rooms_done_flag)
			handle_edges(line, graph);
	}
	ft_printf("%s\n", line);
}

void	handle_ants(char *line, int *n)
{
	if (!ft_strisint(line))
		kill(1);
	if (ft_atoi(line) <= 0)
		kill(0);
	*n = ft_atoi(line);
}

char	set_chk_cmd_flag(char *line, t_graph *const graph, char rooms_done_flag)
{
	char	**to_set;

	to_set = NULL;
	if (rooms_done_flag)
		return (0);
	if (ft_strequ("##start", line))
		to_set = &graph->s;
	else if (ft_strequ("##end", line))
		to_set = &graph->t;
	if (to_set)
	{
		if (*to_set)
			return (0);
		*to_set = SET_ME;
	}
	return (1);
}

void	handle_cmd_comments(char *line, t_graph *graph, char rooms_done_flag)
{

	if (ft_strnequ("##", line, 2))
	{
		if (!set_chk_cmd_flag(line, graph, rooms_done_flag))
			kill(0);
	}
	else
	{
		if (ft_strequ(graph->s, SET_ME) || ft_strequ(graph->t, SET_ME))
			kill(0);
	}
}