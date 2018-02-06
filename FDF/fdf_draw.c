#include "fdf.h"
#define	DX 0
#define	DY 1
#define	YI 2
#define D 3
#define Y 4
#define X 5
#define XI 2


void	fdf_draw(t_map *map)
{
	int		i;
	int		j;
	t_vector	vector;

	i = 0;
	while (i < map->rows - 1)
	{
		j = 0;
		while (j < map->columns - 1)
		{
			if ((map->map[i][j].x + map->offset_x) >= 0 && (map->map[i][j].x + map->offset_x < width) && (map->map[i][j].y + map->offset_y >= 0) && (map->map[i][j].y + map->offset_y < height))
			{
				vector.x0 = map->map[i][j].x * map->step;
		/*		vector.x0 = j;
				vector.y0 = i;
				vector.x1 = j + 1;
				vector.y1 = i;
			*/	vector.y0 = map->map[i][j].y * map->step;
				vector.z0 = map->map[i][j].z * map->step;
				vector.x1 = map->map[i][j + 1].x * map->step;
				vector.y1 = map->map[i][j + 1].y * map->step;
				vector.z1 = map->map[i][j + 1].z * map->step;
				fdf_rotate(&vector, map);
				fdf_put_line(&vector, 0xFFFFFF, map);
				vector.x0 = map->map[i][j].x * map->step;
				vector.y0 = map->map[i][j].y * map->step;
		/*		vector.x0 = j;
				vector.x1 = j;
				vector.y0 = i;
				vector.y1 = i + 1;
		*/		vector.z0 = map->map[i][j].z * map->step;
				vector.x1 = map->map[i + 1][j].x * map->step;
				vector.y1 = map->map[i + 1][j].y * map->step;
				vector.z1 = map->map[i + 1][j].z * map->step;
				fdf_rotate(&vector, map);
				fdf_put_line(&vector, 0xFFFFFF, map);
			}
			j++;
		}
		i++;
	}
}

static void	fdf_put_line_low(t_vector *vector, int color, t_map *map)
{
	int	aux[6];

	aux[DX] = vector->x1 - vector->x0;
	aux[DY] = vector->y1 - vector->y0;
	aux[YI] = 1;
	if (aux[DY] < 0)
	{
		aux[YI] = -1;
		aux[DY] = -aux[DY];
	}
	aux[D] = 2 * aux[DY] - aux[DX];
	aux[Y] = vector->y0;
	aux[X] = vector->x0;
	while (aux[X] < vector->x1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, aux[X] + map->offset_x, aux[Y] + map->offset_y, color);
		if (aux[D] > 0)
		{
			aux[Y] = aux[Y] + aux[YI];
			aux[D] = aux[D] - 2 * aux[DX];
		}
		aux[D] = aux[D] + 2 * aux[DY];
		aux[X]++;
	}
}

static void	fdf_put_line_high(t_vector *vector, int color, t_map *map)
{
	int	aux[6];

	aux[DX] = vector->x1 - vector->x0;
	aux[DY] = vector->y1 - vector->y0;
	aux[XI] = 1;
	if (aux[DX] < 0)
	{
		aux[XI] = -1;
		aux[DX] = -aux[DX];
	}
	aux[D] = 2 * aux[DX] - aux[DY];
	aux[Y] = vector->y0;
	aux[X] = vector->x0;
	while (aux[Y] < vector->y1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, aux[X] + map->offset_x, aux[Y] + map->offset_y, color);
		if(aux[D] > 0)
		{
			aux[X] = aux[X] + aux[XI];
			aux[D] = aux[D] - 2 * aux[DY];
		}
		aux[D] = aux[D] + 2 * aux[DX];
		aux[Y]++;
	}
}



static void	fdf_swap(t_vector *vector)
{
	int x;
	int y;

	x = vector->x0;
	y = vector->y0;
	vector->x0 = vector->x1;
	vector->y0 = vector->y1;
	vector->x1 = x;
	vector->y1 = y;
}

void	fdf_put_line(t_vector *vector, int color, t_map *map)
{
	if (abs(vector->y1 - vector->y0) < abs(vector->x1 - vector->x0))
	{
		if (vector->x0 > vector->x1)
		{
			fdf_swap(vector);
			fdf_put_line_low(vector, color, map);
		}
		else
			fdf_put_line_low(vector, color, map);
	}
	else
		if (vector->y0 > vector->y1)
		{
			fdf_swap(vector);
			fdf_put_line_high(vector, color, map);
		}
		else
			fdf_put_line_high(vector, color, map);
}