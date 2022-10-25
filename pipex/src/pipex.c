/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:48:07 by susong            #+#    #+#             */
/*   Updated: 2022/10/25 11:25:03 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(t_pipe_data *data, char **argv, char **envp)
{
	int	file_des;

	file_des = open(argv[1], O_RDONLY, 0777);
	if (file_des == -1)
		ft_error();
	dup2(data->fd[1], STD_OUT);
	dup2(file_des, STD_IN);
	close(data->fd[0]);
	if (execve(data->operand[0], data->option[0], envp) == -1)
		ft_error();
}

void	parent(t_pipe_data *data, char **argv, char **envp)
{
	int	file_des;

	file_des = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_des == -1)
		ft_error();
	dup2(data->fd[0], STD_IN);
	dup2(file_des, STD_OUT);
	close(data->fd[1]);
	if (execve(data->operand[1], data->option[1], envp) == -1)
		ft_error();
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe_data	*data;

	if (argc == 5)
	{
		data = init_data(argc, argv, envp);
		if (!data)
			ft_error();
		data->pid[0] = fork();
		if (data->pid[0] == -1)
			ft_error();
		if (data->pid[0] == 0)
			child_process(data, argv, envp);
		waitpid(data->pid[0], NULL, 0);
		parent(data, argv, envp);
	}
	else
	{
		write(2, "Error: Bad arguments", 21);
		write(1, "Ex:L ./pipex <file1> <cmd1> <cmd2> <file2>\n", 44);
	}
	return (0);
}

void	ft_error(void)
{
	perror("ERROR");
	exit(EXIT_FAILURE);
}
