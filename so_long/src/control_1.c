/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:36:20 by susong            #+#    #+#             */
/*   Updated: 2022/09/25 20:30:06 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_press(int keycode, t_game_data *data)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(data);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(data);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(data);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(data);
	else if (keycode == KEY_ESC)
		exit(0);
	draw_map(data, 0, 0, 0);
	print_count(data->move);
	return (0);
}

t_game_data	*init_data(void)
{
	t_game_data	*map;

	map = (t_game_data *)malloc(sizeof(t_game_data));
	if (!map)
		print_error(2);
	map->line = 0;
	map->size = 100;
	map->length = 0;
	map->map_data = (char *)malloc(sizeof(char) * 100);
	map->map_data[99] = 0;
	map->player = 0;
	map->exit = 0;
	map->collect = 0;
	map->mlx = mlx_init();
	map->p_collect = mlx_xpm_file_to_image(map->mlx, "./img/Collect.xpm",
			&map->width, &map->height);
	map->p_exit = mlx_xpm_file_to_image(map->mlx, "./img/Exit.xpm",
			&map->width, &map->height);
	map->p_player = mlx_xpm_file_to_image(map->mlx, "./img/Player.xpm",
			&map->width, &map->height);
	map->p_wall = mlx_xpm_file_to_image(map->mlx, "./img/Wall.xpm",
			&map->width, &map->height);
	map->p_base = mlx_xpm_file_to_image(map->mlx, "./img/Base.xpm",
			&map->width, &map->height);
	return (map);
}

void	set_player(t_game_data *data)
{
	int	index;

	index = 0;
	data->cur_x = 0;
	data->cur_y = 0;
	while (index < data->length)
	{
		if (data->map_data[index] == 'P')
			break ;
		index++;
	}
	data->cur_x = index % (data->length / data->line);
	data->cur_y = index / (data->length / data->line);
}
