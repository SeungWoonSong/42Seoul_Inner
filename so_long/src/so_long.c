/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:15:23 by susong            #+#    #+#             */
/*   Updated: 2022/09/24 17:37:53 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	if(argc <= 1)
		print_error(1); //First Error_Nomap #1
	check_map(argv[1]);
	printf("main ended");
}


void print_error(int flag)
{
	printf("Error");

	exit(1);
}
