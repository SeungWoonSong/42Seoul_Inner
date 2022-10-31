/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:53:27 by susong            #+#    #+#             */
/*   Updated: 2022/10/29 21:29:35 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
	t_arg arg;

	if (argc != 5 && argc != 6)
		return (printf("Argument Error : argument shoud be 5 or 6\n"));
	memset(&arg, 0, sizeof(arg));
	if (make_arg_philos(&arg, argc, argv) == 1)
		return (printf("Argument Error : invalid Value"));
}