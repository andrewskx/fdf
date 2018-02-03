/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:41:43 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/03 13:06:07 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft/libft.h"
# include <stdio.h>

typedef struct		s_coord
{
	int x;
	int y;
	int z;
}					t_coord;

typedef	struct		s_map
{
	t_coord	**map;
	int		columns;
	int		rows;
	int		offset_x;
	int		offset_y;
	int		step;
	int		angle_x;
	int		angle_y;
	int		angle_z;
}					t_map;
void		ft_free_double_char(char **str);
void	ft_del_lst(void *content, size_t content_size);
void	fdf_error(char const *str);
void	fdf_map_deallocate(t_map *map);
void	fdf_map_allocate(t_map *map);
void	fdf_read_to_map(char *file, t_map *map);
void	fdf_validation_second_step(t_list *start, t_map *map);
void	fdf_fill_map(char **str, t_map *map, int row);
int		fdf_validation_and_count_columns(char **str);
t_list	*fdf_validation_first_step(char *file, t_map *map);
#endif
