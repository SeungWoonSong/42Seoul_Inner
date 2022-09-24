/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:15:23 by susong            #+#    #+#             */
/*   Updated: 2022/09/24 20:13:45 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_map *map;

	if(argc <= 1)
		print_error(1); //First Error_Nomap #1
	map = check_map(argv[1]);
	if(!map)
		print_error(1);
	printf("%s\n",map->map_data);
	printf("main ended");
}


void print_error(int flag)
{
	printf("Error\n");

	exit(1);
}
