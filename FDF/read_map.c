/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:41:20 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/03 15:13:03 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	print_list(t_list *start)
{
	t_list *ptr;

	ptr = start;
	if (ptr)
		while (ptr)
		{
			write(1, "|", 1);
			ft_putstr((char*)(ptr->content));
			write(1, "|", 1);
			ptr = ptr->next;
			write(1, "\n", 1);
		}
}

void		fdf_validate_line(t_list *start, char *str)
{
	int i;
	int columns;

	i = 0;
	columns = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == ' '))
			if (!((str[i] == '-' && ft_isdigit(str[i + 1]))))
			{
				ft_lstdel(&start, ft_del_lst);
				fdf_error("Invalid map");
			}
		if (str[i] == ' ' && (ft_isdigit(str[i + 1]) || str[i + 1] == '-'))
			columns++;
		i++;
	}
	start->content_size = (size_t)columns + 1;
}

t_list	*fdf_validation_first_step(char *file, t_map *map)
{
	int		fd;
	t_list	*start;
	char	*line;
	int		columns;

	map->rows = -1;
	line = 0;
	start = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		fdf_error("Failed to open the file");
	while (get_next_line(fd, &line))
	{
		ft_lstadd(&start, ft_lstnew((void*)line, ft_strlen(line) + 1));
		fdf_validate_line(start, (char*)(start->content));
		(map->rows)++;
		free(line);
		line = 0;
//		ft_putnbr((int)start->content_size);
//		write(1, "\n", 1);
	}
	return (start);
}

/*void	fdf_fill_map(char **str, t_map *map)
{

	ft_free_double_char(str);
}

void	fdf_validation_second_step(t_list *start, t_map *map)
{
	


*/








void	fdf_read_to_map(char *file, t_map *map)
{
	t_list *start;

	start = fdf_validation_first_step(file, map);
//	print_list(start);
	ft_lstdel(&start, ft_del_lst);
}
