/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:41:20 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/02 17:48:11 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*fdf_validation_first_step(char *file, t_map *map)
{
	int		fd;
	t_list	*start;
	char	*line;

	map->rows = -1;
	line = 0;
	start = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		fdf_error("Failed to open the file");
	while (get_next_line(fd, &line))
	{
		ft_lstadd(&start, ft_lstnew((void*)line, ft_strlen(line)));
		map->rows++;
		free(line);
	}
	return (start);
}

int		fdf_validation_and_count_columns(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				if (str[i][j] == '-' && ft_isdigit(str[i][j + 1]))
					;
				else
					return (-1);
			}		
			j++;
		}
		i++;
	}
	return (i);
}

void	fdf_fill_map(char **str, t_map *map)
{
	int i;

	i = 0;
	while (i < map->columns)
	{
		map->map[map->rows][map->columns].z = ft_atoi((const char *)(str[i]));
		map->map[map->rows][map->columns].y = map->rows;
		map->map[map->rows][map->columns].x = i;
		printf("(%i, %i, %i) ", map->map[map->rows][map->columns].x, map->map[map->rows][map->columns].y,
								map->map[map->rows][map->columns].z);
		i++;
	}
	write(1, "\n", 1);
	map->rows--;
}

void	fdf_validation_second_step(t_list *start, t_map *map)
{
	t_list	*aux;
	char	**str;
	int		columns;

	aux = start;
	str = ft_strsplit((char*)aux->content, ' ');
	map->columns = fdf_validation_and_count_columns(str);
	if (map->columns >= 0)
	{
		columns = map->columns;
		fdf_map_allocate(map);
		ft_putstr("here\ncolumns = ");
		ft_putnbr(columns);
		fdf_fill_map(str, map);
		ft_putstr("after fill\n");
		ft_free_double_char(str);
		aux = aux->next;
		while (aux)
		{
			str = ft_strsplit((const char*)aux->content, ' ');
			(map->columns) = fdf_validation_and_count_columns(str);
			if (map->columns != columns)
				break;
			fdf_fill_map(str, map);
			ft_free_double_char(str);
			aux = aux->next;
		}
	}
	else
		fdf_error("Second step validation");
}


void	fdf_read_to_map(char *file, t_map *map)
{
	t_list *start;

	start = fdf_validation_first_step(file, map);
	fdf_validation_second_step(start, map);
}
