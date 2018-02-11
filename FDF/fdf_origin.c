#include "fdf.h"




void	fdf_init(t_map *map)
{
	map->offset_x = WIDTH / 2 - map->columns / 2;
	map->offset_y = HEIGHT / 2 - map->rows / 2;
	map->reverse = 0;
	map->step = 10;
	map->axe_key = 0;
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
}

void	fdf_move_z_to_origin(t_map *map, int offset, int min, int max)
{
	int i;
	int j;
	int cur;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j].z == max)
				map->map[i][j].color = 0xFFFFFF;
			else if (map->map[i][j].z == min)
				map->map[i][j].color = 0xFF0000;
			else 
			{
				cur = 255 * map->map[i][j].z / max;
				map->map[i][j].color = (((((255 << 8) | cur) << 8) | cur) << 4);
			}
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
			j++;
		}
		i++;
	}
	fdf_init(map);
	fdf_move_z_to_origin(map, (z_max + z_min) / 2, z_min, z_max);
}

