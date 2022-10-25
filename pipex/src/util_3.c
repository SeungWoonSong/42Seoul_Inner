/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:33:45 by susong            #+#    #+#             */
/*   Updated: 2022/10/25 11:21:04 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_array(char **array)
{
	int	index;

	index = 0;
	while (array[index] != NULL)
	{
		free(array[index]);
		index++;
	}
	free(array);
	return ;
}

void	init_util(t_pipe_data *data, int argc, char **argv, int *index)
{
	data->num_command = argc - 3;
	data->total = argc - 3;
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	pipe(data->fd);
	*index = 0;
}
