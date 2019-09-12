/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:11:28 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/11 19:16:04 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	**map_find_str(t_map *map, char *key)
{
	return (map_find(map, key, ft_strlen(key) + 1));
}

char	map_insert_str(t_map *map, char *key, void *val)
{
	return (map_insert(map, key, ft_strlen(key) + 1, val));
}