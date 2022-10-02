/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:01:59 by susong            #+#    #+#             */
/*   Updated: 2022/10/02 17:18:55 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void make_child(t_pipe_data *data, char **envp)
{
	int index;
	int pid;

	index = 0;
	while(index < data->total)
	{
		printf("\nCurrent : %d %d %s\n", data->total, data->num_command, data->operand[index]);
		execute_process(data, envp);
		index++;
	}
	return ;
}


void execute_process(t_pipe_data *data, char **envp)
{
	int pid;
	int number;

	number = data->total - data->num_command;
	data->num_command--;
	pid = fork();
	if(pid == 0)
	{
		change_pipe(data);
		execve(data->operand[number], &data->option[number], envp);
	}
	else
	{
		data->pid[data->total - data->num_command] = pid;
		return ;
	}
}

void change_pipe(t_pipe_data *data)
{
	// 홀수 프로세서, 애들은 00 11사용
	if((data->total - data->num_command) % 2 == 1)
	{
		close(data->fd[1][0]);
		close(data->fd[0][1]);
		dup2(data->fd[0][0], STD_IN);
		dup2(STD_OUT, data->fd[1][1]);
	}
	// 짝수 프로세서, 애들은 10 01 사용
	else
	{
		close(data->fd[0][0]);
		close(data->fd[1][1]);
		dup2(data->fd[1][0], STD_IN);
		dup2(STD_OUT, data->fd[0][1]);
	}
}
