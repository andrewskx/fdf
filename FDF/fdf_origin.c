#include "fdf.h"

void	fdf_move_z_to_origin(t_map *map, int offset)
{
	int i;
	int j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			map->map[i][j].z -= offset;
			j++;
		}
		i++;
	}
}

void	fdf_move_to_origin(t_map *map)
{
	int i;
	int j;
	int z_max;
	int z_min;

	i = 0;
	z_max = map->map[0][0].z;
	z_min = z_max;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			z_max = z_max < map->map[i][j].z ? map->map[i][j].z : z_max;
			z_min = z_min > map->map[i][j].z ? map->map[i][j].z : z_min;
			map->map[i][j].x -= (map->columns / 2);
			map->map[i][j].y -= (map->rows / 2);
		//	ft_putnbr(map->map[i][j].z);
		//	write(1, " ", 1);
			j++;
		}
		i++;
	}
/*	ft_putstr("\nz_max = ");
	ft_putnbr(z_max);
	ft_putstr("\nz_min = ");
	ft_putnbr(z_min);
	ft_putstr("\nmedian = ");
	ft_putnbr((z_min + z_max) / 2);
*/	map->offset_x = width / 2 - map->columns / 2;
	map->offset_y = height / 2 - map->rows / 2;
	map->step = 10;
	map->angle_x =  45 * rad;
	map->angle_y =  0 * rad;
	map->angle_z = -45 * rad;
	map->axe_key = 0;
	map->reverse = 0;
	fdf_move_z_to_origin(map, (z_max + z_min) / 2);
}
