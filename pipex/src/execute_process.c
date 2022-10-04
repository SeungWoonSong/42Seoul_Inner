/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:01:59 by susong            #+#    #+#             */
/*   Updated: 2022/10/04 22:25:07 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void make_child(t_pipe_data *data, char **envp)
{
	int index;
	int pid;

	index = 0;
	if(index++ == 0)
		execute_first(data, envp);
	// while(index < data->total - 1)
	// {
	// 	printf("\nCurrent : %d %d %s\n", data->total, data->num_command, data->operand[index]);
	// 	execute_process(data, envp);
	// 	index++;
	// }
	if(index == data->total - 1)
		execute_last(data, envp);
	return ;
}

void execute_first(t_pipe_data *data, char **envp)
{
	int infile_fd;

	data->pid[0] = fork();
	printf("\n\ndata->pid[0] is %d\n", data->pid[0]);
	if(data->pid[0] == 0)
	{
		infile_fd = open(data->infile, O_RDONLY, 0644);
		// if(infile_fd < 0)
			//error
		dup2(infile_fd, STD_IN);
		dup2(data->fd[0][1], STD_OUT);
		close(data->fd[0][0]);
		close(data->fd[1][1]);
		close(data->fd[1][0]);
		execve(data->operand[0], data->option[0], envp);
	}
	else
		return ;
}

void execute_last(t_pipe_data *data, char **envp)
{
	int outfile_fd;

	data->pid[data->total - 1] = fork();
	if(data->pid[data->total - 1] == 0)
	{
		outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		// if(outfile_fd < 0)
			//error
		dup2(outfile_fd, STD_OUT);
		dup2(data->fd[0][0], STD_IN);
		close(data->fd[0][1]);
		close(data->fd[1][0]);
		close(data->fd[1][1]);
		execve(data->operand[data->total - 1], data->option[data->total - 1], envp);
	}
	else
		return ;
}
// void execute_process(t_pipe_data *data, char **envp)
// {
// 	int pid;
// 	int number;

// 	number = data->total - data->num_command;
// 	data->num_command--;
// 	printf("number is %d\n", number);
// 	printf("execve data is %s %s %s\n", data->operand[number], data->option[number][0],data->option[number][1]);
// 	pid = fork();
// 	if(pid == 0)
// 	{
// 		printf("\nexecute %d process %s\n", data->num_command, data->operand[number]);
// 		change_pipe(data);

// 		execve(data->operand[number], data->option[number], envp);
// 	}
// 	else
// 	{
// 		data->pid[data->total - data->num_command] = pid;
// 		return ;
// 	}
// }

// void change_pipe(t_pipe_data *data)
// {
// 	// 홀수 프로세서, 애들은 01 10사용
// 	printf("IN change pipe %d %d number %d\n", data->total, data->num_command, data->total - data->num_command - 1);
// 	if((data->total - data->num_command) % 2 == 1)
// 	{
// 		printf("First PIPECHANGED\n\n");
// 		close(data->fd[0][1]);
// 		close(data->fd[1][0]);
// 		// dup2(STD_IN, data->fd[0][1]);
// 		// dup2(STD_OUT, data->fd[1][0]);
// 		dup2(data->fd[0][0], STD_IN);
// 		dup2(data->fd[1][1], STD_OUT);
// 		close(data->fd[0][0]);
// 		close(data->fd[1][1]);
// 	}
// 	// 짝수 프로세서, 애들은 10 00 사용xw
// 	else
// 	{
// 		printf("SECOND PIPECHANGED\n\n");
// 		close(data->fd[0][0]);
// 		close(data->fd[1][1]);
// 		// dup2(STD_IN, data->fd[1][1]);
// 		// dup2(STD_OUT,  data->fd[0][0]);
// 		dup2(data->fd[1][0], STD_IN);
// 		dup2(data->fd[0][1], STD_OUT);
// 		close(data->fd[1][0]);
// 		close(data->fd[0][1]);
// 	}
// }
