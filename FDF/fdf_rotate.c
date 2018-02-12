#include "fdf.h"

inline void	fdf_rotate_x(t_vector *vector, t_coord *p1, t_coord *p2, t_map *map)
{
//	int y;

//	y = vector->y0;
	vector->y0 = cos(map->angle_x) * p1->y - sin(map->angle_x) * p1->z;
	vector->z0 = sin(map->angle_x) * p1->y + cos(map->angle_x) * p1->z;
//	y = vector->y1;
	vector->y1 = cos(map->angle_x) * p2->y - sin(map->angle_x) * p2->z;
	vector->z1 = sin(map->angle_x) * p2->y + cos(map->angle_x) * p2->z;
}

inline void	fdf_rotate_y(t_vector *vector, t_coord *p1, t_coord *p2, t_map *map)
{
//	int x;

//	x = vector->x0;
	vector->x0 = cos(map->angle_y) * p1->x + sin(map->angle_y) * p1->z;
	vector->z0 = -sin(map->angle_y) * p1->x + cos(map->angle_y) * p1->z;
	//x = vector->x1;
	vector->x1 = cos(map->angle_y) * p2->x + sin(map->angle_y) * p2->z;
	vector->z1 = -sin(map->angle_y) * p2->x + cos(map->angle_y) * p2->z;
}

inline void	fdf_rotate_z(t_vector *vector, t_coord *p1, t_coord *p2, t_map *map)
{
//	int x;

//	x = vector->x0;
	vector->x0 = cos(map->angle_z) * p1->x - sin(map->angle_z) * p1->y;
	vector->y0 = sin(map->angle_z) * p1->x + cos(map->angle_z) * p1->y;
//	x = vector->x1;
	vector->x1 = cos(map->angle_z) * p2->x - sin(map->angle_z) * p2->y;
	vector->y1 = sin(map->angle_z) * p2->x + cos(map->angle_z) * p2->y;
}

extern inline void fdf_rotate(t_vector *vector, t_coord *p1, t_coord *p2, t_map *map)
{
	fdf_rotate_x(vector, p1, p2, map);
	fdf_rotate_y(vector, p1, p2, map);
	fdf_rotate_z(vector, p1, p2, map);
	vector->x0 += map->offset_x;
	vector->x1 += map->offset_x;
	vector->y0 += map->offset_y;
	vector->y1 += map->offset_y;
}
