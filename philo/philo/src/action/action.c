/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:49:00 by susong            #+#    #+#             */
/*   Updated: 2022/12/20 13:54:43 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	eating(t_philos *philos)
{
	print_action(philos, "is eating");
	philos_sleep(philos->time_eat);
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
}

void	sleeping(t_philos *philos)
{
	print_action(philos, "is sleeping");
	philos_sleep(philos->time_sleep);
	print_action(philos, "is thinking");
}

void	taking_forks(t_philos *philos)
{
	int	only_one;

	only_one = 0;
	if (philos->num_philos == 1)
		only_one = 1;
	pthread_mutex_lock(philos->left_fork);
	print_action(philos, "has taken a fork");
	pthread_mutex_lock(philos->right_fork);
	if (only_one == 1)
		return ;
	print_action(philos, "has taken a fork");
}

void	*daily_routine(void *argument)
{
	t_philos	*philos;

	philos = argument;
	// printf("we are working,%d\n",philos->name);
	while (philos->dead == 0 && philos->fulfilled == 0)
	{
		taking_forks(philos);
		eating(philos);
		sleeping(philos);
	}
	return (0);
}
