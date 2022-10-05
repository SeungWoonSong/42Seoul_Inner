/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:48:07 by susong            #+#    #+#             */
/*   Updated: 2022/10/05 11:35:32 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe_data	*data;
	int			status;

	data = init_data(argc, argv, envp);
	if (!data)
		ft_error(errno);
	make_child(data, envp);
	close_pipe(data);
	while (wait(&status) != -1)
		;
	return (0);
}

void	ft_error(int err)
{
	write(2, "ERROR NO : ", 12);
	strerror(err);
	exit(1);
}

void	close_pipe(t_pipe_data *data)
{
	close(data->fd[1][0]);
	close(data->fd[0][0]);
	close(data->fd[1][1]);
	close(data->fd[0][1]);
	return ;
}
