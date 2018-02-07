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

//extern inline void	fdf_rotate(t_vector *vector, t_map *map)
//{
//	int x;
//	int y;	
//	int z;
	
//	fdf_rotate_x(vector, map);
//	fdf_rotate_y(vector, map);
//	fdf_rotate_z(vector, map);
//	fdf_scale(vector, map);
//	z = vector->z0;
//	x = vector->x0;
//	y = vector->y0;
	/*vector->x0 = cos(map->angle_y) * (sin(map->angle_z) * y + cos(map->angle_z) * x) - sin(map->angle_y) * z;
	vector->y0 = sin(map->angle_x) * (cos(map->angle_y) * z + sin(map->angle_y) * (sin(map->angle_z) * y + cos(map->angle_z) * x)) + cos(map->angle_x) * (cos(map->angle_z) * y - sin(map->angle_z) * x);
	x = vector->x1;
	z = vector->z1;
	y = vector->y1;
	vector->x1 = cos(map->angle_y) * (sin(map->angle_z) * y + cos(map->angle_z) * x) - sin(map->angle_y) * z;
	vector->y1 = sin(map->angle_x) * (cos(map->angle_y) * z + sin(map->angle_y) * (sin(map->angle_z) * y + cos(map->angle_z) * x)) + cos(map->angle_x) * (cos(map->angle_z) * y - sin(map->angle_z) * x);
	*/

//}

inline void	fdf_rotate_x(t_vector *vector, t_map *map)
{
	int y;

	y = vector->y0;
	vector->y0 = cos(map->angle_x) * y - sin(map->angle_x) * vector->z0;
	vector->z0 = sin(map->angle_x) * y + cos(map->angle_x) * vector->z0;
	y = vector->y1;
	vector->y1 = cos(map->angle_x) * y - sin(map->angle_x) * vector->z1;
	vector->z1 = sin(map->angle_x) * y + cos(map->angle_x) * vector->z1;
}

inline void	fdf_rotate_y(t_vector *vector, t_map *map)
{
	int x;

	x = vector->x0;
	vector->x0 = cos(map->angle_y) * x + sin(map->angle_y) * vector->z0;
vector->z0 = -sin(map->angle_y) * x + cos(map->angle_y) * vector->z0;
	x = vector->x1;
	vector->x1 = cos(map->angle_y) * x + sin(map->angle_y) * vector->z1;
	vector->z1 = -sin(map->angle_y) * x + cos(map->angle_y) * vector->z1;
}

inline void	fdf_rotate_z(t_vector *vector, t_map *map)
{
	int x;

	x = vector->x0;
	vector->x0 = cos(map->angle_z) * x - sin(map->angle_z) * vector->y0;
	vector->y0 = sin(map->angle_z) * x + cos(map->angle_z) * vector->y0;
	x = vector->x1;
	vector->x1 = cos(map->angle_z) * x - sin(map->angle_z) * vector->y1;
	vector->y1 = sin(map->angle_z) * x + cos(map->angle_z) * vector->y1;
}

extern inline void fdf_rotate(t_vector *vector, t_map *map)
{
	fdf_rotate_x(vector, map);
	fdf_rotate_y(vector, map);
	fdf_rotate_z(vector, map);
}
