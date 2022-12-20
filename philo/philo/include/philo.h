/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:53:18 by susong            #+#    #+#             */
/*   Updated: 2022/12/20 15:31:56 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERROR 1
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct t_philos
{
	int				meal_counter;
	int				name;
	long			last_eat;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				num_philos;
	int				dead;
	int				fulfilled;
	pthread_t		philos_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*lock_screen;
}	t_philos;

typedef struct t_table
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				dead;
	int				all_fulfilled;
	pthread_mutex_t	lock_screen;
	pthread_mutex_t	*forks;
	t_philos		*philos;
}	t_table;

//action
void	*daily_routine(void *argument);
void	eating(t_philos *philos);
void	sleeping(t_philos *philos);
void	taking_forks(t_philos *philos);

// Watcher
void	watcher(t_table *table);
int		check_fulfilled(t_table *table, int *pig_philos, int index);
void	death_sequence(t_table *table);
void	death_sequence2(t_table *table);
// Check
int		check_argument(int argc, char **argv);

// Parsing
int		make_table(t_table *arg, int argc, char **argv);

int		init_forks(t_table *arg);
int		init_screen(t_table *arg);

// Make Philos
int		init_philos(t_table *table, t_philos *philo, int philo_name);
// check_table
int		check_table(t_table table, int argc);

//make_philos
int		make_philos(t_table *table);
// Library
int		ft_atoi(const char *str);
void	print_action(t_philos *philos, char *word);

// Library2
long	ft_time(void);
void	philos_sleep(long m_second);

//destroy_free
void	destroy_and_free(t_table *table);
#endif
