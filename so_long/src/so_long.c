/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:15:23 by susong            #+#    #+#             */
/*   Updated: 2022/09/24 21:07:38 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/so_long.h"
// #include "../include/study.h"
#include "mlx.h"


int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "putImage");
	img = mlx_xpm_file_to_image(mlx, "./img/spider.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);
	return (0);
}




// int main(int argc, char **argv)
// {
// 	t_map *map;

// 	if(argc <= 1)
// 		print_error(1); //First Error_Nomap #1
// 	map = check_map(argv[1]);
// 	if(!map)
// 		print_error(1);
// 	printf("%s\n",map->map_data);
// 	printf("main ended");
// }


// void print_error(int flag)
// {
// 	printf("Error\n");

// 	exit(1);
// }
