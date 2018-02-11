/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:30:30 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/03 16:33:32 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	fdf_key(int key, t_map *map)
{
	if (key == 53)
	{
		fdf_map_deallocate(map);
		exit(3);
	}
	else if (key == 27)
	{
		if (map->step > 0)
		{
			ft_putstr("\nMinimize");
			map->step /= 1.05;
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			fdf_draw(map);
		}
	}
	else if (key == 24)
	{
		if (map->step * map->columns < width)
		{
			ft_putstr("\nMaximize");
			map->step *= 1.05;
			mlx_clear_window(map->mlx_ptr, map->win_ptr);
			fdf_draw(map);
		}
	}
	else if (key == 125)
	{
		ft_putstr("\nMove down");
		map->offset_y += 3;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		fdf_draw(map);
	}
	else if (key == 126)
	{
		ft_putstr("\nMove up");
		map->offset_y -= 3;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		fdf_draw(map);
	}
	else if (key == 123)
	{
		ft_putstr("\nMove left");
		map->offset_x -= 1;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		fdf_draw(map);
	}
	else if (key == 124)
	{
		ft_putstr("\nMove right");
		map->offset_x += 1;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		fdf_draw(map);
	}
	else if (key == 7)
	{
		map->angle_x += 0.0174 * 7;
		ft_putstr("\nRotate towards X");
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		fdf_draw(map);
	}
	else if (key == 16)
	{
		map->angle_y += 0.0174 * 7;
		ft_putstr("\nRotate towards Y");
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		fdf_draw(map);
	}
	else if (key == 6)
	{
		map->angle_z += 0.0174 * 7;
		ft_putstr("\nRotate towards Z");
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		fdf_draw(map);
	}
	ft_putstr(" key ->");
	ft_putnbr(key);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_map *map)
{
	write(1, "\nx = ", 10);
	ft_putnbr(button);
	write(1, "\ny = ", 1);
	ft_putnbr(x);
	write(1, "y = ", 4);
	ft_putnbr(y);
	return (1);
}
*/
int	main(int arg, char **argv)
{
	t_map	map;

	if (arg != 2)
		fdf_error("No arguments provided");
	fdf_read_to_map(argv[1], &map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, WIDTH, HEIGHT, argv[1]);
	fdf_draw(&map);
	mlx_hook(map.win_ptr, 2, 0, fdf_key, &map);
	mlx_hook(map.win_ptr, 4, 0, fdf_mouse_hook, &map);
	mlx_hook(map.win_ptr, 5, 0, fdf_button_release_hook, &map);
	mlx_hook(map.win_ptr, 6, 0, fdf_motion_hook, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
