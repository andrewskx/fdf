#include "fdf.h"

int	main(void)
{
	t_map map;

	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, 500, 300, "expr");
	
	map.image.img_ptr = mlx_new_image(map.mlx_ptr, 500, 600);
	map.image.img_data = mlx_get_data_addr(map.image.img_ptr,
			&(map.image.bits_per_pixel), 
			&(map.image.size_line),
			&(map.image.endian));
	printf("\nbits_per_pixel = %i\
		\nsize_line = %i\
		\nendian = %i", map.image.bits_per_pixel, map.image.size_line, map.image.endian);
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 300; j++)
		{
			*(int *)(map.image.img_data + (i * 300 + j) * 4) = 122234 + j * i;
			j++;
		}
	}
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, map.image.img_ptr, 0, 0);
	mlx_loop(map.mlx_ptr);
	return (0);
}
