/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:35:38 by susong            #+#    #+#             */
/*   Updated: 2022/12/20 14:37:25 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	make_philos(t_table *table)
{
	int	index;

	index = 0;
	table->philos = (t_philos *)malloc(sizeof(t_philos) * table->num_philos);
	if (!(table->philos))
		return (ERROR);
	while (index < table->num_philos)
	{
		init_philos(table, &(table->philos[index]), index + 1);
		pthread_create(&(table->philos[index].philos_thread),
			NULL, daily_routine, &table->philos[index]);
		pthread_detach(table->philos[index].philos_thread);
		index++;
		usleep(200);
	}
	watcher(table);
	return (0);
}

int	init_philos(t_table *table, t_philos *philo, int philo_name)
{
	philo->name = philo_name ;
	philo->left_fork = &(table->forks[philo_name - 1]);
	philo->right_fork = &(table->forks[philo_name % table->num_philos]);
	philo->time_die = table->time_die;
	philo->time_eat = table->time_eat;
	philo->time_sleep = table->time_sleep;
	philo->lock_screen = &(table->lock_screen);
	philo->meal_counter = 0;
	philo->num_philos = table->num_philos;
	philo->last_eat = ft_time();
	philo->dead = 0;
	philo->fulfilled = 0;
	return (0);
}
