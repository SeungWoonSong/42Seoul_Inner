/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:28:01 by nouswong          #+#    #+#             */
/*   Updated: 2022/10/29 22:32:13 by nouswong         ###   ########.fr       */
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
	check_error = init_philos(arg);
	check_error = init_forks(arg);
	check_error = init_screen(arg);
	if (check_error == 1)
		return (1);
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
	}

	return (0);
}

int init_screen(t_arg *arg)
{

	return (0);
}