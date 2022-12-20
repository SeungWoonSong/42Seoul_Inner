/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:08:10 by susong            #+#    #+#             */
/*   Updated: 2022/12/20 11:37:56 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	check_table(t_table table, int argc)
{
	int	err_cmd;

	err_cmd = 0;
	if (table.num_philos <= 0)
		err_cmd = 1;
	if (table.time_die <= 0)
		err_cmd = 2;
	if (table.time_eat <= 0)
		err_cmd = 3;
	if (table.time_sleep <= 0)
		err_cmd = 4;
	if (argc == 6 && table.must_eat <= 0)
		err_cmd = 5;
	if (err_cmd == 0)
		return (0);
	else
		printf("Argument Error: %d command is invalid could be more\n", err_cmd);
	return (ERROR);
}
