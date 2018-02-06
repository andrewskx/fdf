#include "fdf.h"

extern inline void	fdf_scale(t_vector *vector, t_map *map)
{
	vector->x0 *= map->step;
	vector->x1 *= map->step;
	vector->y0 *= map->step;
	vector->y1 *= map->step;
	vector->z0 *= map->step;
	vector->z1 *= map->step;
}

extern inline void	fdf_rotate(t_vector *vector, t_map *map)
{
	int x;
	int y;	
	int z;
	
//	fdf_scale(vector, map);
	z = vector->z0;
	x = vector->x0;
	y = vector->y0;
	vector->x0 = cos(map->angle_y) * (sin(map->angle_z) * y + cos(map->angle_z) * x) - sin(map->angle_y) * z;
	vector->y0 = sin(map->angle_x) * (cos(map->angle_y) * z + sin(map->angle_y) * (sin(map->angle_z) * y + cos(map->angle_z) * x)) + cos(map->angle_x) * (cos(map->angle_z) * y - sin(map->angle_z) * x);
	x = vector->x1;
	z = vector->z1;
	y = vector->y1;
	vector->x1 = cos(map->angle_y) * (sin(map->angle_z) * y + cos(map->angle_z) * x) - sin(map->angle_y) * z;
	vector->y1 = sin(map->angle_x) * (cos(map->angle_y) * z + sin(map->angle_y) * (sin(map->angle_z) * y + cos(map->angle_z) * x)) + cos(map->angle_x) * (cos(map->angle_z) * y - sin(map->angle_z) * x);
}
