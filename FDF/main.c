/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:30:30 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/02 17:41:02 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int arg, char **argv)
{
	t_map	map;

	if (arg != 2)
		fdf_error("No arguments provided");
	fdf_read_to_map(argv[1], &map);
	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < (map.columns); j++)
		{
			printf("(%i, %i, %i) ", i, map.map[i][j].y, map.map[i][j].z);
		}
		printf("\n");
	}*/
	return (0);
}
