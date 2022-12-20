/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:59:53 by nouswong          #+#    #+#             */
/*   Updated: 2022/12/20 13:51:51 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	if (!str)
		return (0);
	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - 48);
	return (result * sign);
}

void	print_action(t_philos *philos, char *word)
{
	long	current_time;

	current_time = ft_time();
	pthread_mutex_lock(philos->lock_screen);
	printf("%ld %d %s\n", current_time, philos->name, word);
	pthread_mutex_unlock(philos->lock_screen);
	return ;
}
