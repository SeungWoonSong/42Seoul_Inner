/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:48:07 by susong            #+#    #+#             */
/*   Updated: 2022/10/04 22:21:56 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipe_data *data;
	int			status;

	data = init_data(argc, argv, envp);
	if(!data)
		return(0);
	//Make Child Process

	printf("\n$123OPENFILE END\n");
	make_child(data, envp);
	// open file -> to fd[0][1]

	// open_file(data);
	printf("BEFORE waitn\n\n");
	// while(wait(&status));
	// write_file(data);
	// char bur[1024];
	// close(data->fd[1][1]);
	// close(data->fd[0][0]);
	// close(data->fd[0][1]);
	// status = read(data->fd[1][0], bur, 1024);
	// printf("status is %d", status);
	// printf("\n\n in main\n%s\n\n", bur);
	// printf("MAIN ENDED");

	close(data->fd[1][0]);

}

void ft_error(int err)
{
	write(2, "ERROR NO : ", 12);
	strerror(err);
	exit(1);
}

void print_pipe(int a, int b)
{
	char buf[1024];

}
