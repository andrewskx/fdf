/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_alloc_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:47:51 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/02 17:12:14 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_map_deallocate(t_map *map)
{
	while (map->rows)
	{
		free(map->map[map->rows]);
		map->rows--;
	}
	free(map->map);
}

void	fdf_map_allocate(t_map *map)
{
	int i;

	i = 0;
	map->map = (t_coord**)malloc(sizeof(t_coord*) * (map->rows + 1));
	while (i < (map->rows + 1))
	{
		map->map[i] = (t_coord*)malloc(sizeof(t_coord) * map->columns);
		i++;
	}
}
