/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:15:23 by susong            #+#    #+#             */
/*   Updated: 2022/09/26 09:23:43 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	*game_data;

	if (argc <= 1)
		print_error (1);
	game_data = init_data();
	game_data->win = 0;
	game_data->move = 0;
	game_data->exit_flag = 0;
	if (!check_map(game_data, argv[1]))
		print_error(1);
	start_game(game_data);
	free(game_data->map_data);
	free(game_data);
	return (0);
}

void	start_game(t_game_data *game_data)
{
	make_window(game_data);
	draw_map(game_data, 0, 0, 0);
	set_player(game_data);
	mlx_key_hook(game_data->win, &key_press, game_data);
	mlx_hook(game_data->win, 17, 0, &end_red, game_data);
	mlx_loop(game_data->mlx);
	return ;
}

void	print_error(int flag)
{
	if (flag == 0)
		exit(0);
	write(1, "Error\n", 6);
	exit(1);
}

int	end_red(t_game_data *data)
{
	if (data->map_data != NULL)
		free(data->map_data);
	if (data)
		free(data);
	exit(1);
}
