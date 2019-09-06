/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:58:32 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/06 10:50:34 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define SIZE 2

t_map		*map_init(void)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	new->size = SIZE;
	new->map = malloc(SIZE * sizeof(void*));
	ft_bzero(new->map, SIZE * sizeof(void*));
	return (new);
}

int			map_hash(void *key, size_t key_size)
{
	unsigned int	sum;

	sum = 0;
	while (key_size)
	{
		sum += *((char*)key);
		key = ((char*)key) + 1;
		key_size--;
	}
	return (sum % SIZE);
}

t_map_node	*map_node_new(void *key, size_t key_size, void *val)
{
	t_map_node	*new;

	if (!key || !(new = (t_map_node*)malloc(sizeof(t_map_node))))
		return (NULL);
	new->key = key;
	new->key_size = key_size;
	new->val = val;
	new->next = NULL;
	return (new);
}

char		map_insert(t_map *map, void *key, size_t key_size, void *val)
{
	t_map_node	*new;

	if (!(new = map_node_new(key, key_size, val)))
		return (0);
	if (!map || !map->map || !key)
		return (0);
	new->next = map->map[map_hash(key, key_size)];
	map->map[map_hash(key, key_size)] = new;
	return (1);
}

void		**map_find(t_map *map, char *key, size_t key_size)
{
	t_map_node	*it;

	if (!map || !map->map || !key)
		return (NULL);
	it = map->map[map_hash(key, key_size)];
	while (it)
	{
		if (it->key_size == key_size && !ft_memcmp(it->key, key, key_size))
			break ;
		it = it->next;
	}
	if (!it)
		return (NULL);
	return (&it->val);
}
