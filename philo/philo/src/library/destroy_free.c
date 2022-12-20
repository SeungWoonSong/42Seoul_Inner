/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:27 by susong            #+#    #+#             */
/*   Updated: 2022/12/20 15:24:41 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	destroy_and_free(t_table *table)
{
	int	index;

	index = 0;
	pthread_mutex_destroy(&(table->lock_screen));
	while (index < table->num_philos)
	{
		pthread_mutex_destroy(&table->forks[index]);
		index++;
	}
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
	return ;
}
