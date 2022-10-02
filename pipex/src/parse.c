/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:59:33 by susong            #+#    #+#             */
/*   Updated: 2022/10/02 16:23:13 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// typedef struct t_pipe_data
// {
// 	int		num_command;
// 	char	**operand;
// 	int		fd[2][2];
// 	int		*pid;
// }				t_pipe_data;


t_pipe_data *init_data(int argc, char **argv, char **envp)
{
	t_pipe_data *data;
	int index;
	char **path;

	index = 0;
	// malloc data;
	data = (t_pipe_data *)malloc(sizeof(t_pipe_data));
	// How many Cmd do i have;
	data->num_command = argc - 3;
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	// Init Pipe(2);
	pipe(data->fd[0]);
	pipe(data->fd[1]);
	// make pid array
	// printf("Make operand started");
	data->pid = (int *)malloc(sizeof(int) * (data->num_command + 1));
	data->pid[data->num_command] = 0;
	// malloc operand array;
	data->operand = (char **)malloc(sizeof(char *) * (data->num_command + 1));
	data->operand[data->num_command] = 0;
	// make operand array;
	// make operand option;
	data->option  = make_option(data, &argv);
	path = make_path(envp);
	while(index < data->num_command)
	{
		data->operand[index] = check_path(argv[index + 2], path);
		index++;
	}
	free_array(path);
	return(data);
}

char *check_path(char *argv, char **envp)
{
	int		index_envp;
	char	*check_array;
	char	**envp_list;

	index_envp = 0;
	check_array = 0;
	//envp already fixed;
	while(envp[index_envp])
	{
		check_array = ft_strjoin(envp[index_envp], argv);
		if(access(check_array, X_OK) == 0)
			return(check_array);
		else
			safe_free(check_array);
		index_envp++;
	}
	return(argv);
}

char **make_path(char **envp)
{
	int index;
	char **temp;
	char **result;

	index = 0;
	while(check_string(envp[index], "PATH"))
		index++;
	temp = ft_split(envp[index + 1], '=');
	result = ft_split(temp[1], ':');
	free_array(temp);
	temp = result;
	result = make_path_2(result);
	free_array(temp);
	return(result);
}

char **make_option(t_pipe_data *data, char ***argv)
{
	int index;
	int index_argv;

	index = 0;
	index_argv = 0;
	data->option = (char **)malloc(sizeof(char *) * (data->num_command + 1));
	data->option[data->num_command] = 0;
	while(index < data->num_command)
	{
		while((*argv)[index + 2][index_argv] != ' ')
			index_argv++;
		(*argv)[index + 2][index_argv] = 0;
		data->option[index] = ft_substr((*argv)[index + 2], index_argv + 1,ft_strlen((*argv)[index + 2]) - index_argv);		index++;
	}
	return (data->option);
}

// option making
// argv split -> argv == operand
