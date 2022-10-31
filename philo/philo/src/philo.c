/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:53:27 by susong            #+#    #+#             */
/*   Updated: 2022/10/31 15:47:41 by susong           ###   ########.fr       */
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
