/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:38:26 by susong            #+#    #+#             */
/*   Updated: 2022/09/24 20:17:42 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_data(t_map *map, char *line)
{
	int count;

	count = map->line + 1;
	if(!is_wall(count, line))
		return(0);
	if(!is_valid(line, map))
		return(0);
	if(!collect_data_map(map, line))
		return(0);
	return (1);
}

int is_wall(int count, char *line)
{
	int index;

	index = 0;
	if(count == 1)
	{
		while(line[index] != '\n')
		{
			if(line[index] != '1')
				return (0);
			index++;
		}
	}
	else
	{
		while(line[index] != '\n')
			index++;
		if(line[0] != '1' || line[index - 1] != '1')
			return (0);
	}
	return (1);
}

int is_valid(char *line, t_map *map)
{
	int index;
	int	size;

	index = 0;
	if(!(map->line == 0))
		size = map->length / map->line;
	while(line[index] != '\n')
	{
		if(!(line[index] == '0' || line[index] == '1' ||
			line[index] == 'C' || line[index] == 'E' || line[index] == 'P'))
			return(0);
		index++;
	}

	if(!(size == index + 1) && map->line != 0 )
		return (0);
	if(index < 1)
		return(0);
	return(1);
}

int collect_data_map(t_map *map, char *line)
{
	int index;

	index = 0;
	while(line[index] != '\n')
	{
		if(line[index] == 'C')
			map->collect += 1;
		else if(line[index] == 'P')
			map->player +=1;
		else if(line[index] == 'E')
			map->exit += 1;
		index++;
	}
	return (1);
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
	map->player = 0;
	map->exit = 0;
	map->collect = 0;
	return(map);
}

int check_last_wall(t_map *map)
{
	int size;
	int index;

	index = 0;
	size = map->length / map->line;
	while(map->map_data[index + map->length - size] != '\n')
	{
		if(map->map_data[index + map->length - size] != '1')
			return(0);
		index++;
	}
	return(1);
}
