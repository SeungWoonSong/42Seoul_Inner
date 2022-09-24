/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:57:58 by susong            #+#    #+#             */
/*   Updated: 2022/09/24 18:33:48 by susong           ###   ########.fr       */
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
	printf("map size : %d a length : %d\n", map_file->size, map_file->length);
	while(index)
	{
		line = get_next_line(fd);
		if(!line)
			index = 0;
		else
			if(!(append_result(map_file, line)))
				print_error(2);
	}


	// close(fd);
	// printf("check_map ended\n");
	// printf("%s", map_file->map_data);
	// return(map_file);
}

t_map	*init_map()
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if(!map)
		print_error(2);
	map->line = 0;
	map->size = 100;
	map->length = 0;
	map->map_data = (char *)malloc(sizeof(char) * 100);
	map->map_data[99] = 0;
	return(map);
}
void make_map_big(t_map *map)
{
	char *temp;
	int index;

	printf("make map big\n\n");
	index = 0;
	temp = (char *)malloc(sizeof(char) * map->size * 2);
	temp[map->size * 2 - 1] = 0;
	while(index < map->size)
	{
		temp[index] = map->map_data[index];
		index++;
	}
	map->size *= 2;
}
int append_result(t_map *a, char *b)
{
	int index;

	index = 0;

	// if(!(check_data(a, b)))
	// 	return(0);
	printf("a size : %d a length : %d\n", a->size, a->length);
	if((a->size) - (a->length) - 1 < ft_strlen(b))
		make_map_big(a);
	while(index < ft_strlen(b))
	{
		a->map_data[a->length + index] = b[index];
		index++;
	}
	a->map_data[a->length+index] = 0;
	a->length += index;
	return(1);
}

