/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:29:51 by nouswong          #+#    #+#             */
/*   Updated: 2022/10/29 22:28:37 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Error == 1, Ok == 0
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
