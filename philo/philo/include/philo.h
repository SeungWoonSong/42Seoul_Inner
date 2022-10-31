/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:53:18 by susong            #+#    #+#             */
/*   Updated: 2022/10/31 14:38:18 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>

typedef struct t_philos
{
	int num_meal; // 얼마나 지금 먹었는지
	int id; // 이름
	int time_die; // 얼마나 버틸 수 있는가?
	int time_eat; // 먹는 시간
	int time_sleep; // 자는 시간
	int must_eat; // 최소 먹어야되는 양
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *lock_screen;

} t_philos;

typedef struct t_arg
{
	int num_philos;
	int time_die;
	int time_eat;
	int time_sleep;
	int must_eat;
	int dead;
	pthread_mutex_t lock_screen;
	pthread_mutex_t *forks;
	t_philos *philos;
} t_arg;

// typedef struct timeval
// {
// 	time_t tv_sec;
// 	suseconds_t tv_uses;
// };

// Check
int check_argument(int argc, char **argv);

// Parsing
int make_arg_philos(t_arg *arg, int argc, char **argv);
int init_philos(t_arg *arg);
int init_forks(t_arg *arg);
int init_screen(t_arg *arg);

// Library
int ft_atoi(const char *str);
void print_action(t_philos *philos, char *word);

// Library2
long ft_time();
void philos_sleep(long m_second);
#endif
