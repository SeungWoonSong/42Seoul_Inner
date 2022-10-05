/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:01:59 by susong            #+#    #+#             */
/*   Updated: 2022/10/05 11:28:38 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void make_child(t_pipe_data *data, char **envp)
{
	if(data->total == data->num_command)
	{
		printf("FIRST\n");
		execute_first(data, envp);
		data->num_command -= 1;
	}
	while(data->num_command > 1)
	{
		printf("middle %d\n", data->total - data->num_command);
		execute_middle(data, envp);
		data->num_command -= 1;
	}
	if(data->num_command == 1)
	{
		printf("LAST\n");
		execute_last(data, envp);
		data->num_command -= 1;
	}
	return ;
}

void execute_first(t_pipe_data *data, char **envp)
{
	int infile_fd;

	data->pid[0] = fork();
	if(data->pid[0] == 0)
	{
		infile_fd = open(data->infile, O_RDONLY, 0644);
		if(infile_fd < 0)
			ft_error(errno);
		dup2(infile_fd, STD_IN);
		dup2(data->fd[0][1], STD_OUT);
		close_pipe(data);
		execve(data->operand[0], data->option[0], envp);
	}
	else
		return ;
}

void execute_last(t_pipe_data *data, char **envp)
{
	int outfile_fd;

	data->pid[data->total - data->num_command] = fork();
	if(data->pid[data->total - data->num_command] == 0)
	{
		outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if(outfile_fd < 0)
			ft_error(errno);
		dup2(outfile_fd, STD_OUT);
		if(data->total - data->num_command % 2 == 1)
		{
			dup2(data->fd[1][0], STD_IN);
			close_pipe(data);
		}
		else
		{
			dup2(data->fd[0][0], STD_IN);
			close_pipe(data);
		}
		execve(data->operand[data->total - 1], data->option[data->total - 1], envp);
	}
	else
		return ;
}

void execute_middle(t_pipe_data *data, char **envp)
{
	data->pid[data->total - data->num_command] = fork();
	if(data->pid[data->total - data->num_command] == 0)
	{
		if(data->total - data->num_command % 2 == 1)
		{
			dup2(data->fd[0][0], STD_IN);
			dup2(data->fd[1][1], STD_OUT);
			close_pipe(data);
		}
		else
		{
			dup2(data->fd[1][0], STD_IN);
			dup2(data->fd[0][1], STD_OUT);
			close_pipe(data);
		}
		execve(data->operand[data->total - data->num_command], data->option[data->total - data->num_command], envp);
	}
	else
		return ;
}
