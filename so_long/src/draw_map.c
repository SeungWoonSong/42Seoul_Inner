/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:10:11 by susong            #+#    #+#             */
/*   Updated: 2022/09/25 17:00:06 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	make_window(t_game_data *data)
{
	data->width =  (data->length / data->line) * 64;
	data->height = data->line * 64;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "SO_LONG");
	void ;
}

void	draw_map(t_game_data *data)
{
	int index;
	int	wid;
	int	hei;

	wid = 0;
	hei = 0;
	index = 0;
	while(index < data->length && data->map_data[index])
	{
		if(data->map_data[index] == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->p_wall, wid * 64, hei * 64);
		// else if(data->map_data[index] == '0')
		// 	mlx_put_image_to_window(data->mlx, data->win, data->p_base, wid * 64, hei * 64);

		if(data->map_data[index] == '\n')
			hei += 1;
		index++;
	}

}
