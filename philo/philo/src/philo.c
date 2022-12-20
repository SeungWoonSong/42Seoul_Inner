/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:53:27 by susong            #+#    #+#             */
/*   Updated: 2022/12/20 13:55:07 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_philos(t_philos *philos);

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
	// destroy_mutex(&table);
	// free_all(&table);
}

void print_philos(t_philos *philos)
{
	printf("mead Count : %d\n name : %d \n last eat : %ld \n must eat : %d", philos->meal_counter, philos->name, philos->last_eat, philos->must_eat);
}
