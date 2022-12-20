/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:53:27 by susong            #+#    #+#             */
/*   Updated: 2022/12/20 15:35:54 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (printf("Argument Error : argument should be 5 or 6\n"));
	memset(&table, 0, sizeof(table));
	if (make_table(&table, argc, argv) == ERROR)
		return (printf("Argument Error : invalid Value"));
	if (check_table(table, argc) == ERROR)
		return (ERROR);
	make_philos(&table);
	destroy_and_free(&table);
	return (0);
}
