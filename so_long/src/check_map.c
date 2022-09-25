/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:57:58 by susong            #+#    #+#             */
/*   Updated: 2022/09/25 20:18:17 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map(t_game_data *game_data, char *map_filename)
{
	char	*line;
	char	*result;
	int		fd;
	int		index;

	index = 1;
	result = 0;
	fd = open(map_filename, O_RDONLY);
	while (index)
	{
		line = get_next_line(fd);
		if (!line)
			index = 0;
		else
			if (!(append_result(game_data, line)))
				print_error(2);
		free(line);
	}
	check_last_wall(game_data);
	if (!(game_data->exit >= 1 && game_data->collect >= 1 && \
		game_data->player == 1))
		return (0);
	close(fd);
	return (1);
}

void	make_map_big(t_game_data *map)
{
	char	*temp;
	int		index;

	index = 0;
	temp = (char *)malloc(sizeof(char) * map->size * 2);
	temp[map->size * 2 - 1] = 0;
	while (index < map->length)
	{
		temp[index] = map->map_data[index];
		index++;
	}
	free(map->map_data);
	map->map_data = temp;
	map->size *= 2;
}

int	append_result(t_game_data *a, char *b)
{
	int	index;

	index = 0;
	if (!(check_data(a, b)))
		return (0);
	if ((a->size) - (a->length) - 1 < ft_strlen(b))
		make_map_big(a);
	while (index < ft_strlen(b))
	{
		a->map_data[a->length + index] = b[index];
		index++;
	}
	a->map_data[a->length + index] = 0;
	a->length += index;
	a->line += 1;
	return (1);
}
