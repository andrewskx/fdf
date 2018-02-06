#include "fdf.h"

int	fdf_key(int key, t_map *map)
{
	if (key == 53)
	{
		fdf_map_deallocate(map);
		exit(0);
	}
	else if (key == 7 || key == 16 || key == 6)
	{
		ft_putstr("\nkey = ");
		ft_putnbr(key);
		if (!map->axe_key)
			map->axe_key = key;
		else
			map->axe_key = 0;
	}
	return (0);
}

int	fdf_mouse_hook(int button, int x, int y, t_map *map)
{
	map->button = button;
	map->last_x = x;
	map->last_y = y;
	return (0);
}

int	fdf_motion_hook(int x, int y, t_map *map)
{
	if (map->button == 1)
	{
		ft_putstr("\nMotion hook");
		if (map->axe_key == 7)
		{
			ft_putstr("\nX key");
			if (map->last_y < y)
				map->angle_x  *= (5 * 0.0174);
			else if (map->last_y > y)
				map->angle_x /= (5 * 0.0174);
		//	map->angle_x = map->last_y < y ? (map->angle_x * 5 * 0.0174) : (map->angle_x / 5 * 0.0174);
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			fdf_draw(map);
		}
		else if (map->axe_key == 16)
		{
			ft_putstr("\nY key");
			map->angle_y = map->last_x < x ? (map->angle_y * 5 * 0.0174) : (map->angle_y / 5 * 0.0174);
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			fdf_draw(map);
		}
		else if (map->axe_key == 6)
		{
			ft_putstr("\nZ key");
			map->angle_z = map->last_x < x ? (map->angle_z * 5 * 0.0174) : (map->angle_z / 5 * 0.0174);
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			fdf_draw(map);
		}

	}
	else if (map->button == 2)
	{
		map->step = map->last_y < y ? (map->step * 1.05) : (map->step / 1.05);
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		fdf_draw(map);
	}
	return (0);
}

int	fdf_button_release_hook(int button, int x, int y, t_map *map)
{
	map->button = 0;
	map->axe_key = 0;
	return (0);
}
