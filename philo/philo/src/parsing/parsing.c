/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:28:01 by nouswong          #+#    #+#             */
/*   Updated: 2022/12/20 14:22:25 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	make_table(t_table *table, int argc, char **argv)
{
	int	check_error;

	check_error = 0;
	if (check_argument(argc, argv) == ERROR)
		return (ERROR);
	table->num_philos = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	table->dead = 0;
	table->all_fulfilled = 0;
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = -1;
	check_error = init_forks(table);
	check_error = init_screen(table);
	if (check_error == 1)
		return (ERROR);
	return (0);
}

int	check_argument(int argc, char **argv)
{
	int	i;
	int	index;

	index = 1;
	while (index < argc)
	{
		i = 0;
		while (argv[index][i])
		{
			if (argv[index][i] < '0' || argv[index][i] > '9')
				return (ERROR);
			i++;
		}
		index++;
	}
	return (0);
}

int	init_forks(t_table *table)
{
	int	index;

	index = 0;
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->num_philos);
	if (!(table->forks))
		return (ERROR);
	while (index < table->num_philos)
	{
		if (pthread_mutex_init(&(table->forks[index]), NULL) != 0)
			return (ERROR);
		index++;
	}
	return (0);
}

int	init_screen(t_table *arg)
{
	if (pthread_mutex_init(&(arg->lock_screen), NULL) != 0)
		return (1);
	return (0);
}
