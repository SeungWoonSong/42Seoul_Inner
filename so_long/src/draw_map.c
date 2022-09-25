/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:10:11 by susong            #+#    #+#             */
/*   Updated: 2022/09/25 20:32:37 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	make_window(t_game_data *data)
{
	data->width = (data->length / data->line) * 64;
	data->height = data->line * 64;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "SO_LONG");
	return ;
}

void	draw_map(t_game_data *data, int index, int wid, int hei)
{
	while (index < data->length && data->map_data[index])
	{
		if (data->map_data[index] == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->p_wall,
				wid * 64, hei * 64);
		else if (data->map_data[index] != '1')
			mlx_put_image_to_window(data->mlx, data->win, data->p_base,
				wid * 64, hei * 64);
		if (data->map_data[index] == 'P')
			mlx_put_image_to_window(data->mlx, data->win, data->p_player,
				wid * 64, hei * 64);
		else if (data->map_data[index] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->p_collect,
				wid * 64, hei * 64);
		else if (data->map_data[index] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->p_exit,
				wid * 64, hei * 64);
		if (data->map_data[index] == '\n')
			draw_map_util(&hei, &wid);
		else
			wid++;
		index++;
	}
}

void	print_count(int count)
{
	char	*temp;

	temp = ft_itoa(count);
	write(1, "Current Count is ", 18);
	write(1, ft_itoa(count), ft_count(count));
	write(1, "\n", 1);
	free(temp);
}

void	draw_map_util(int *hei, int *wid)
{
	*hei += 1;
	*wid = 0;
}
