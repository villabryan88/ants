/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnv_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:28:36 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/09 16:16:46 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int	fnv_hash(unsigned char *buffer, size_t n)
{
	unsigned int	h;
	size_t			i;

	h = 2166136261;
	i = 0;
	while (i < n)
	{
		h = h ^ buffer[i];
		h = h * 16777619;
		i++;
	}
	return (h);
}
