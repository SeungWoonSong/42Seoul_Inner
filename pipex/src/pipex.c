/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:48:07 by susong            #+#    #+#             */
/*   Updated: 2022/10/02 16:22:56 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipe_data *data;

	data = init_data(argc, argv, envp);
	if(!data)
		return(0);
	//Make Child Process
	// make_child(data, envp);

	printf("MADED");
	printf("cmd : %s %s %s\n", data->operand[0], data->operand[1], data->operand[2]);
	printf("fd : %d %d %d %d\n", data->fd[0][0], data->fd[0][1], data->fd[1][0], data->fd[1][1]);
	printf("num command : %d\n",data->num_command);
	printf("%s %s\n", data->infile, data->outfile);
	// start_program(argument, fds, envp);

}

void ft_error(int err)
{
	write(2, "ERROR NO : ", 12);
	strerror(err);
	exit(1);
}
