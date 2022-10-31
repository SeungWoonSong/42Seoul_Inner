/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:15:01 by susong            #+#    #+#             */
/*   Updated: 2022/10/31 14:43:07 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long ft_time()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return((long)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void philos_sleep(long m_second)
{
	long time;

	time = ft_time();
	usleep(m_second * 990);
	while(ft_time() < time + m_second)
		usleep(5);
}
