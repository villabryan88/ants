/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:12:38 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/05 22:37:38 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#define	SET_ME "#set_me"

void	kill(char print){
	ft_printf("ERROR\n");
	if (print)
		perror(NULL);
	exit(0);
}

char	*get_start_end(char *line){
	char	*st;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	if (!tmp || !(st = ft_strdup(tmp[0])))
	{
		kill(1);
		return (NULL);
	}
	ft_strarrdel(tmp);
	return (st);
}
void	handle_commands(char **s, char **t, char *line){
	if (ft_strequ("##start", line))
		*s = SET_ME;
	else if (ft_strequ("##end", line))
		*t = SET_ME;
	else if (ft_strequ(*s, SET_ME))
		*s = get_start_end(line);
	else if (ft_strequ(*t, SET_ME))
		*t = get_start_end(line);
}

int		hashtag_error_check(char *line, int rooms_done_flag){
	static char	start_flag = 0;
	static char	end_flag = 0;

	if (ft_strnequ(line, "##", 2)){
		if (rooms_done_flag)
			return (1);
		if (!start_flag && ft_strequ("##start", line))
			start_flag = 1;
		else if (!end_flag && ft_strequ("##end", line))
			end_flag = 1;
		else
			return (1);
	}
	return (0);
}

int		room_error_check(char *line, 
				char *rooms_done_flag, t_graph	*const	graph)
{
	char	**tmp;
	int		err = 0;

	tmp = ft_strsplit(line, ' ');
	if (ft_arrlen(tmp, sizeof(void*)) == 3)
	{
		if (!ft_strisint(tmp[1]) || !ft_strisint(tmp[2]) || tmp[0][0] == 'L')
			err = 1;
		if (map_find(graph->adj_map, tmp[0]))
			err = 1;
	}
	else if (graph->s && graph->t && 
				!ft_strequ(SET_ME, graph->s) && !ft_strequ(SET_ME, graph->t))
		*rooms_done_flag = 1;
	else
		err = 1;
	ft_strarrdel(tmp);
	return (err);
}

int		links_error_check (char *line){
	char	**tmp;
	int		err = 0;

	tmp = ft_strsplit(line, '-');
	if (ft_arrlen(tmp, sizeof(void*)) == 2)
		(void)tmp; // check dictionary if valid entry
	else
		err = 1;
	ft_strarrdel(tmp);
	return (err);	
}

int		err_and_zone_check(char *line, t_graph	*const	graph, int n,
									char *rooms_done_flag)
{
	if (n == -1){
		return (!ft_strisint(line) || ft_atoi(line) < 0);
	}
	if (ft_strnequ("#", line, 1)){
		if (ft_strequ(graph->s, SET_ME) || ft_strequ(graph->t, SET_ME))
			return (1);
		return hashtag_error_check(line, *rooms_done_flag);
	}
	if (!*rooms_done_flag)
	{
		if (room_error_check(line, rooms_done_flag, graph))
			return (1);
	}
	if (*rooms_done_flag)
		return links_error_check(line);
	return (0);
}

t_graph	*graph_init(){
	t_graph	*new = malloc(sizeof(t_graph));

	new->adj_map = map_init();
	new->s = NULL;
	new->t = NULL;
	return (new);
}

void	handle_links(char *line){
	(void)line;
}

void	handle_rooms(char *line){
	(void)line;
}

void	handle_input(char *line, t_graph *const graph, int *n,
										char *rooms_done_flag)
{
	if (ft_strnequ("##", line, 2) || ft_strequ(SET_ME, graph->s) ||
										ft_strequ(SET_ME, graph->t))
		handle_commands(&graph->s, &graph->t, line);
	if (*n == -1)
		*n = ft_atoi(line);
	else if (!ft_strnequ("#", line, 1))
	{
		if (rooms_done_flag)
			handle_links(line);
		else
			handle_rooms(line);
	}
	if (!ft_strnequ("#", line, 1) || ft_strnequ("##", line, 2))
		ft_printf("%s\n", line);
}

int		main(void)
{
	char			*line;
	t_graph	*const	graph = graph_init();
	int				n = -1;
	char			rooms_done_flag = 0;

	while (get_next_line(0, &line) > 0)
	{
		if (!line || err_and_zone_check(line, graph, n, &rooms_done_flag))
			kill(0);
		handle_input(line, graph, &n, &rooms_done_flag);
		free(line);
	}
	ft_printf("s: %s, t: %s\n", graph->s, graph->t);
	return (0);
}
