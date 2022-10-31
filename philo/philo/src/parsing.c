/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:28:01 by nouswong          #+#    #+#             */
/*   Updated: 2022/10/31 13:36:20 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int make_arg_philos(t_arg *arg, int argc, char **argv)
{
	int check_error;

	check_error = 0;
	if (check_argument(argc, argv) == 1)
		return (1);
	arg->num_philos = ft_atoi(argv[1]);
	arg->time_die = ft_atoi(argv[2]);
	arg->time_eat = ft_atoi(argv[3]);
	arg->time_sleep = ft_atoi(argv[4]);
	arg->dead = 0;
	if (argc == 6)
		arg->must_eat = ft_atoi(argv[5]);
	check_error = init_forks(arg);
	check_error = init_screen(arg);
	check_error = init_philos(arg);
	if (check_error == 1)
		return (1);
	return (0);
}

int check_argument(int argc, char **argv)
{
	int i;
	int index;

	index = 1;
	while (index < argc)
	{
		i = 0;
		while (argv[index][i])
		{
			if (argv[index][i] <= '0' || argv[index][i] > '9')
				return (1);
			i++;
		}
		index++;
	}
	return (0);
}

int init_philos(t_arg *arg)
{
	int index;

	index = 0;
	arg->philos = (t_philos *)malloc(sizeof(t_philos) * arg->num_philos);
	if (!arg->philos)
		return (1);
	while (index < arg->num_philos)
	{
		arg->philos[index].id = index + 1;
		arg->philos[index].left_fork = &(arg->forks[index]);
		arg->philos[index].right_fork = &(arg->forks[(index + 1) % 5]);
		arg->philos[index].time_die = arg->time_die;
		arg->philos[index].time_eat = arg->time_eat;
		arg->philos[index].time_sleep = arg->time_sleep;
		arg->philos[index].lock_screen = &(arg->lock_screen);
		arg->philos[index].num_meal = 0;
		index++;
	}

	return (0);
}

int init_forks(t_arg *arg)
{
	int index;

	index = 0;
	arg->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * arg->num_philos);
	if (!(arg->forks))
		return (1);
	while (index < arg->num_philos)
	{
		if(pthread_mutex_init(&(arg->forks[index]), NULL) != 0)
			return (1);
		index++;
	}
	return (0);
}

int init_screen(t_arg *arg)
{
	if (pthread_mutex_init(&(arg->lock_screen), NULL) != 0)
		return(1);
	return (0);
}
