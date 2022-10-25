/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:59:33 by susong            #+#    #+#             */
/*   Updated: 2022/10/25 11:19:36 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipe_data	*init_data(int argc, char **argv, char **envp)
{
	t_pipe_data	*data;
	int			index;
	char		**path;

	data = (t_pipe_data *)malloc(sizeof(t_pipe_data));
	if (!data)
		ft_error();
	init_util(data, argc, argv, &index);
	data->pid = (int *)malloc(sizeof(int) * (data->num_command + 1));
	if (!data->pid)
		ft_error();
	data->pid[data->num_command] = 0;
	data->operand = (char **)malloc(sizeof(char *) * (data->num_command + 1));
	if (!data->operand)
		ft_error();
	data->operand[data->num_command] = 0;
	path = make_path(envp);
	while (index < data->num_command)
	{
		data->operand[index] = check_path(argv[index + 2], path);
		index++;
	}
	data->option = make_option(data, &argv);
	free_array(path);
	return (data);
}

char	*check_path(char *argv, char **envp)
{
	int		index_envp;
	char	*check_array;
	char	**temp;

	index_envp = 0;
	check_array = 0;
	while (envp[index_envp])
	{
		temp = ft_split(argv, ' ');
		check_array = ft_strjoin(envp[index_envp], temp[0]);
		if (access(check_array, X_OK) == 0)
		{
			free_array(temp);
			return (check_array);
		}
		else
		{
			free_array(temp);
			safe_free(check_array);
		}
		index_envp++;
	}
	return (argv);
}

char	**make_path(char **envp)
{
	int		index;
	char	**temp;
	char	**result;

	index = 0;
	while (check_string(envp[index], "PATH"))
		index++;
	temp = ft_split(envp[index], '=');
	result = ft_split(temp[1], ':');
	free_array(temp);
	temp = result;
	result = make_path_2(result);
	free_array(temp);
	return (result);
}

char	***make_option(t_pipe_data *data, char ***argv)
{
	int		index;
	int		index_argv;
	char	*temp;

	index = 0;
	index_argv = 0;
	data->option = (char ***)malloc(sizeof(char **) * (data->num_command + 1));
	if (!data->option)
		ft_error();
	data->option[data->num_command] = 0;
	while (index < data->num_command)
	{
		data->option[index] = ft_split((*argv)[index + 2], ' ');
		temp = data->option[index][0];
		data->option[index][0] = ft_strjoin("", data->operand[index]);
		safe_free(temp);
		index++;
	}
	return (data->option);
}
