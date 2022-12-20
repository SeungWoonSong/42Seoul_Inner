/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:56:59 by susong            #+#    #+#             */
/*   Updated: 2022/12/20 15:32:03 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	watcher(t_table *table)
{
	int			index;
	int			pig_philos;

	index = 0;
	pig_philos = 0;
	while (table->dead == 0 && table->all_fulfilled == 0)
	{
		if (ft_time() - table->philos[index].last_eat > table->time_die)
		{
			death_sequence(table);
			print_action(&table->philos[index], "is dead");
			pthread_mutex_lock(&table->lock_screen);
		}
		if (check_fulfilled(table, &pig_philos, index) == 1)
		{
			pthread_mutex_lock(&table->lock_screen);
			printf("Every philosophers are fulfilled\n");
			break ;
		}
		index = (index + 1) % table->num_philos;
		if (index == 0)
			pig_philos = 0;
		usleep(50);
	}
}

int	check_fulfilled(t_table *table, int *pig_philos, int index)
{
	if (table->philos[index].meal_counter >= table->must_eat
		&& table->must_eat != -1)
		*pig_philos = *pig_philos + 1;
	if (*pig_philos == table->num_philos - 1 && table->num_philos != 1)
	{
		death_sequence2(table);
		return (1);
	}
	return (0);
}

void	death_sequence(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->num_philos)
	{
		table->philos[index].dead = 1;
		index++;
	}
	table->dead = 1;
	return ;
}

void	death_sequence2(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->num_philos)
	{
		table->philos[index].fulfilled = 1;
		index++;
	}
	table->all_fulfilled = 1;
	return ;
}
