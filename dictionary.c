/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:58:32 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/05 21:39:01 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

#define SIZE 40000
// extern const struct	s_map_class {
// 	void			(*insert)(char*, t_list*);
// 	void			*(*find)(char*)
// }					t_map_class;

t_map    *map_init(void)
{
    t_map   *new = malloc(sizeof(t_map));

	new->size = SIZE;
	new->map = malloc(sizeof(SIZE * sizeof(void*)));
	ft_bzero(new->map, sizeof(SIZE * sizeof(void*)));	
	return (new);
}

int		map_hash(char *key)
{
	return ((int)key % SIZE);
}

void	map_insert(t_map *map, char *key, void *val)
{
	t_list	*new;

	if (!(new = ft_lstnew(val, 0)))
		kill(1);
	if (!map || !map->map || !key || !val)
	{
		ft_printf("map_insert invalid parameters");
		return ;
	}
	ft_lstadd(&map->map[map_hash(key)], new);
}

void	**map_find(t_map *map, char *key){
	t_list	*it;

	if (!map || !map->map || !key)
		return (NULL);
	it = map->map[map_hash(key)];
	while (it && !ft_strequ(((t_list*)it->content)->content, key))
		it = it->next;
	if (!it)
		return (NULL);
	return (&((t_list*)it->content)->next);
}

