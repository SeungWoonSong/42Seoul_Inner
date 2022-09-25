/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:15:23 by susong            #+#    #+#             */
/*   Updated: 2022/09/25 17:01:14 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
// #include "../include/study.h"

int main(int argc, char **argv)
{
	t_game_data *game_data;

	if(argc <= 1)
		print_error(1); //First Error_Nomap #1
	game_data = init_data();
	if(!check_map(game_data, argv[1]))
		print_error(1);
	printf("%s\n",game_data->map_data);
	printf("main ended");
	start_game(game_data);
	//free_map(map);
}


void start_game(t_game_data *game_data)
{

	game_data->win = mlx_new_window(game_data->mlx, 1920, 1080, "putImage");
	mlx_xpm_file_to_image(game_data->mlx, "./img/Wall.xpm", &game_data->width,&game_data->height);
	// mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, data);
	mlx_put_image_to_window(game_data->mlx, game_data->win, game_data->p_wall, 400, 64);
	// img = mlx_xpm_file_to_image(mlx, "./img/Floor.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(mlx, win, img, 300, 300);


	// make_window(game_data);
	// draw_map(game_data);
	mlx_loop(game_data->mlx);
	return ;
}

void print_error(int flag)
{
	printf("Error\n");
	exit(flag);
}
