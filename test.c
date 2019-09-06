/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvilla <bvilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:16:33 by bvilla            #+#    #+#             */
/*   Updated: 2019/09/06 10:57:53 by bvilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#define MAP_SIZE 40000

int main(){
    t_map   *map = map_init(MAP_SIZE);

    map_insert(map, "hi", sizeof("hi"), "hola");
    map_insert(map, "bye", sizeof("bye"), "adios");
    map_insert(map, "red", sizeof("red"), "rojo");


    ft_printf("%s\n", *map_find(map, "hi", sizeof("hi")));
    ft_printf("%s\n", *map_find(map, "bye", sizeof("bye")));
    ft_printf("%s\n", *map_find(map, "red", sizeof("red")));
    ft_printf("%p\n", map_find(map, "h", sizeof("h")));
    return (0);
}