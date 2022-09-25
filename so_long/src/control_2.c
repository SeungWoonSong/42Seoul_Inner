/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:42:04 by susong            #+#    #+#             */
/*   Updated: 2022/09/25 20:23:30 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_left(t_game_data *data)
{
	int	current;
	int	num_per_line;

	num_per_line = data->length / data->line;
	current = (data->cur_y * num_per_line) + data->cur_x;
	if (data->map_data[current - 1] == '1')
		return ;
	else if (data->map_data[current - 1] == 'C')
		data->collect -= 1;
	else if (data->map_data[current - 1] == 'E')
		if (data->collect == 0)
			exit(1);
	data->map_data[current] = '0';
	data->map_data[current - 1] = 'P';
	data->move += 1;
	set_player(data);
	return ;
}

void	move_right(t_game_data *data)
{
	int	current;
	int	num_per_line;

	num_per_line = data->length / data->line;
	current = (data->cur_y * num_per_line) + data->cur_x;
	if (data->map_data[current + 1] == '1')
		return ;
	else if (data->map_data[current + 1] == 'C')
		data->collect -= 1;
	else if (data->map_data[current + 1] == 'E')
		if (data->collect == 0)
			exit(1);
	data->map_data[current] = '0';
	data->map_data[current + 1] = 'P';
	data->move += 1;
	set_player(data);
	return ;
}

void	move_up(t_game_data *data)
{
	int	current;
	int	num_per_line;

	num_per_line = data->length / data->line;
	current = (data->cur_y * num_per_line) + data->cur_x;
	if (data->map_data[current - num_per_line] == '1'
		|| current - num_per_line < num_per_line)
		return ;
	else if (data->map_data[current - num_per_line] == 'C')
		data->collect -= 1;
	else if (data->map_data[current - num_per_line] == 'E')
		if (data->collect == 0)
			exit(1);
	data->map_data[current] = '0';
	data->map_data[current - num_per_line] = 'P';
	data->move += 1;
	set_player(data);
	return ;
}

void	move_down(t_game_data *data)
{
	int	current;
	int	num_per_line;

	num_per_line = data->length / data->line;
	current = (data->cur_y * num_per_line) + data->cur_x;
	if (data->map_data[current + num_per_line] == '1'
		|| current + num_per_line > data->length)
		return ;
	else if (data->map_data[current + num_per_line] == 'C')
		data->collect -= 1;
	else if (data->map_data[current + num_per_line] == 'E')
		if (data->collect == 0)
			exit(1);
	data->map_data[current] = '0';
	data->map_data[current + num_per_line] = 'P';
	data->move += 1;
	set_player(data);
	return ;
}
