/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:52:56 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/24 19:45:08 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	map_del(t_map *del)
{
	size_t		i;
	t_map_node	*next;

	i = 0;
	while (i < del->size)
	{
		while(del->map[i])
		{
			next = del->map[i]->next;
			free(del->map[i]);
			del->map[i] = next;
		}
		i++;
	}
	free(del->map);
	free(del);
}
