/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:36:20 by susong            #+#    #+#             */
/*   Updated: 2022/09/25 16:44:14 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int key_press(int keycode, t_param *param) // 어떤 키가 눌렸는지 판단하고,
{                                                // 정의된 행동을 수행하는 함수
	if (keycode == KEY_W || keycode == KEY_UP)        // W 키를 누르면 param.x값이 1 증가한다.
		param->x++;
	else if (keycode == KEY_S || keycode == KEY_DOWN)   // S 키를 누르면 param.x값이 1 감소한다.
		param->x--;
	else if (keycode == KEY_A || keycode == KEY_LEFT)   // A 키를 누르면 param.y값이 1 증가한다.
		param->y++;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)   // D 키를 누르면 param.y값이 1 감소한다.
		param->y--;
	else if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
		exit(0);
	printf("(x, y): (%d, %d)\n", param->x, param->y); // param의 값 확인
	return (0);
}

t_game_data	*init_data()
{
	t_game_data	*map;

	map = (t_game_data *)malloc(sizeof(t_game_data));
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
	map->cur_x = 0;
	map->cur_y = 0;
	map->mlx = mlx_init();
	map->win = 0;
	map->move = 0;
	// map->p_collect = mlx_xpm_file_to_image(map->mlx, "./img/Collect.xpm", &map->width, &map->height);
	// map->p_exit = mlx_xpm_file_to_image(map->mlx, "./img/Exit.xpm", &map->width, &map->height);
	// map->p_player = mlx_xpm_file_to_image(map->mlx, "./img/Player.xpm", &map->width, &map->height);
	map->p_wall = mlx_xpm_file_to_image(map->mlx, "./img/Wall.xpm", &map->width, &map->height);
	map->p_base = mlx_xpm_file_to_image(map->mlx, "./img/Base.xpm", &map->width, &map->height);

	return(map);
}
