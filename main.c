/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:12:38 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/06 15:12:15 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#define	SET_ME "#set_me"
#define MAP_SIZE 40000

void	kill(char print){
	ft_printf("ERROR\n");
	if (print)
		perror(NULL);
	exit(0);
}

t_graph	*graph_init(){
	t_graph	*new = malloc(sizeof(t_graph));

	new->adj_map = map_init(MAP_SIZE);
	new->s = NULL;
	new->t = NULL;
	return (new);
}

void	handle_edges(char *line){
	char	**tmp;

	tmp = ft_strsplit(line, '-');
	if (ft_arrlen(tmp, sizeof(void*)) == 2)
		(void)line; // add edge to dictionary
	else
		kill(0);
	ft_strarrdel(tmp);
}

void	handle_ants(char *line, int *n)
{
	if (!ft_strisint(line))
		kill(1);
	if (ft_atoi(line) < 0)
		kill(0);
	*n = ft_atoi(line);
}

void	handle_hashtag(char * line, t_graph *graph, char rooms_done_flag)
{
	char	**to_set;

	to_set = (char**)"abort";
	if (!ft_strnequ("##", line, 2))
	{
		if (ft_strequ(graph->s, SET_ME) || ft_strequ(graph->t, SET_ME))
			kill(0);
	}
	else {
		if (rooms_done_flag)
			kill(0);
		if (ft_strequ("##start", line))
			to_set = &graph->s;
		else if (ft_strequ("##end", line))
			to_set = &graph->t;
		if (*to_set)
			kill(0);
		*to_set = SET_ME;
	}
}

void	handle_rooms(char *line, t_graph *const graph, char *rooms_done_flag)
{
	char	**tmp;

	if (!(tmp = ft_strsplit(line, ' ')))
		kill(1);
	if (ft_arrlen(tmp, sizeof(void*)) == 3)
	{
		if (!ft_strisint(tmp[1]) || !ft_strisint(tmp[2]) || tmp[0][0] == 'L')
			kill(0);
		if (map_find(graph->adj_map, tmp[0], ft_strlen(tmp[0])))
			kill(0);
		if (ft_strequ(SET_ME, graph->s))
			if (!(graph->s = ft_strdup(tmp[0])))
				kill(1);
		if (ft_strequ(SET_ME, graph->t))
			if (!(graph->t = ft_strdup(tmp[0])))
				kill(1);
		//add room to dictionary
	}
	else if (graph->s && graph->t && 
				!ft_strequ(SET_ME, graph->s) && !ft_strequ(SET_ME, graph->t))
		*rooms_done_flag = 1;
	else
		kill(0);
	ft_strarrdel(tmp);
}

int		main(void)
{
	char			*line;
	t_graph	*const	graph = graph_init();
	int				n = -1;
	char			rooms_done_flag;

	rooms_done_flag = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (n == -1)
			handle_ants(line, &n);
		else if (ft_strnequ("#", line, 1))
			handle_hashtag(line, graph, rooms_done_flag);
		else
		{
			if (!rooms_done_flag)
				handle_rooms(line, graph, &rooms_done_flag);
			if (rooms_done_flag)
				handle_edges(line);
		}
		if (!ft_strnequ("#", line, 1) || ft_strnequ("##", line, 2))
			ft_printf("%s\n", line);
	}
	if (!line)
		kill(1);
	ft_printf("s: %s, t: %s\n", graph->s, graph->t);
	return (0);
}
