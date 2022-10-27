/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:48:07 by susong            #+#    #+#             */
/*   Updated: 2022/10/25 11:48:56 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(t_pipe_data *data, char **argv, char **envp)
{
	int	file_des;

	file_des = open(argv[1], O_RDONLY, 0777);
	if (file_des == -1)
		ft_error(0);
	dup2(data->fd[1], STD_OUT);
	dup2(file_des, STD_IN);
	close(data->fd[0]);
	close(data->fd[1]);
	if (execve(data->operand[0], data->option[0], envp) == -1)
		ft_error(1);
}

void	parent(t_pipe_data *data, char **argv, char **envp)
{
	int	file_des;

	file_des = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_des == -1)
		ft_error(0);
	dup2(data->fd[0], STD_IN);
	dup2(file_des, STD_OUT);
	close(data->fd[1]);
	close(data->fd[0]);
	if (execve(data->operand[1], data->option[1], envp) == -1)
		ft_error(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe_data	*data;

	if (argc == 5)
	{
		data = init_data(argc, argv, envp);
		if (!data)
			ft_error(0);
		data->pid[0] = fork();
		if (data->pid[0] == -1)
			ft_error(0);
		if (data->pid[0] == 0)
			child_process(data, argv, envp);
		waitpid(data->pid[0], NULL, WNOHANG);
		parent(data, argv, envp);
	}
	else
	{
		write(2, "Error: Bad argument\n", 21);
		write(2, "Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 43);
		exit(1);
	}
	return (0);
}

void	ft_error(int err)
{
	if (err == 1)
	{
		perror("command not found");
		exit(127);
	}
	perror("ERROR");
	exit(EXIT_FAILURE);
}
