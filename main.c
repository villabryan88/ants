/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:12:38 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/05 15:58:48 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#define	SET_ME "#set_me"

char	*get_start_end(char *line){
	char	*st;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	st = ft_strdup(tmp[0]);
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

int		hashtag_error_check(char *line, int rooms_complete_flag){
	static char	start_flag = 0;
	static char	end_flag = 0;

	if (ft_strnequ(line, "##", 2)){
		if (rooms_complete_flag)
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

int		room_error_check(char *line, char *rooms_complete_flag, char *s, char *t)
{
	char	**tmp;
	int		err = 0;

	tmp = ft_strsplit(line, ' ');
	if (ft_arrlen(tmp, sizeof(void*)) == 3)
	{
		if (!ft_strisint(tmp[1]) || !ft_strisint(tmp[2]) || tmp[0][0] == 'L')
			err = 1;
	}
	else if (s && t && !ft_strequ(SET_ME, s) && !ft_strequ(SET_ME, t))
		*rooms_complete_flag = 1;
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

int		input_line_error_check(char *line, char *s, char *t)
{
	static char n_complete_flag = 0;
	static char rooms_complete_flag = 0;

	if (!n_complete_flag){
		n_complete_flag = 1;
		return (!ft_strisint(line) || ft_atoi(line) < 0);
	}
	if (ft_strnequ("#", line, 1)){
		if (ft_strequ(s, SET_ME) || ft_strequ(t, SET_ME))
			return (1);
		return hashtag_error_check(line, rooms_complete_flag);
	}
	if (!rooms_complete_flag)
	{
		if (room_error_check(line, &rooms_complete_flag, s, t))
			return (1);
	}
	if (rooms_complete_flag)
		return links_error_check(line);
	return (0);
}

t_graph	*graph_init(){
	t_graph	*new = malloc(sizeof(t_graph));

	new->map = map_init();
	new->s = NULL;
	new->t = NULL;
	return (new);
}

int		main()
{
	char			*line;
	t_graph	*const	graph = graph_init();
	int				n = -1;
	
	while (get_next_line(0, &line) > 0){
		if (input_line_error_check(line, graph->s, graph->t))
		{
			ft_printf("ERROR\n");
			free(line);
			return (0);
		}
		else
		{
			if (n == -1)
				n = ft_atoi(line);
			if (ft_strnequ("##", line, 2) || 
					ft_strequ(SET_ME, graph->s) || ft_strequ(SET_ME, graph->t))
				handle_commands(&graph->s, &graph->t, line);
			if (!ft_strnequ("#", line, 1) || ft_strnequ("##", line, 2))
				ft_printf("%s\n", line);
		}
		free(line);
	}
	ft_printf("s: %s, t: %s\n", graph->s, graph->t);
	return (0);
}
