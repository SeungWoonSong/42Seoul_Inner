/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:57:58 by susong            #+#    #+#             */
/*   Updated: 2022/09/24 20:10:42 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map *check_map(char *map_filename)
{
	char *line;
	char *result;
	int fd;
	int index;
	t_map *map_file;

	index = 1;
	result = 0;
	map_file = init_map();
	fd = open(map_filename, O_RDONLY);
	while(index)
	{
		line = get_next_line(fd);
		if(!line)
			index = 0;
		else
			if(!(append_result(map_file, line)))
				print_error(2);
		free(line);
	}
	check_last_wall(map_file);
	if(!(map_file->exit >= 1 && map_file->collect >= 1 && \
		map_file->player == 1))
		return (0);
	close(fd);
	return(map_file);
}


void make_map_big(t_map *map)
{
	char *temp;
	int index;

	index = 0;
	temp = (char *)malloc(sizeof(char) * map->size * 2);
	temp[map->size * 2 - 1] = 0;
	while(index < map->length)
	{
		temp[index] = map->map_data[index];
		index++;
	}
	free(map->map_data);
	map->map_data = temp;
	map->size *= 2;
}

int append_result(t_map *a, char *b)
{
	int index;

	index = 0;
	if(!(check_data(a, b)))
		return(0);

	if((a->size) - (a->length) - 1 < ft_strlen(b))
		make_map_big(a);
	while(index < ft_strlen(b))
	{
		a->map_data[a->length + index] = b[index];
		index++;
	}
	a->map_data[a->length+index] = 0;
	a->length += index;
	a->line += 1;
	return(1);
}

