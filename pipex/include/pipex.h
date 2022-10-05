/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:17:02 by susong            #+#    #+#             */
/*   Updated: 2022/10/05 11:44:54 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

typedef struct t_pipe_data
{
	int		num_command;
	int		total;
	char	**operand;
	char	***option;
	int		fd[2][2];
	int		*pid;
	char	*infile;
	char	*outfile;
}				t_pipe_data;

//main
void		ft_error(int error_num);
void		close_pipe(t_pipe_data *data);

//parse
t_pipe_data	*init_data(int argc, char **argv, char **envp);
char		*check_path(char *argv, char **envp);
char		**make_path(char **envp);
char		***make_option(t_pipe_data *data, char ***argv);

//execute_process
void		make_child(t_pipe_data *data, char **envp);

// void change_pipe(t_pipe_data *data);
void		execute_first(t_pipe_data *data, char **envp);
void		execute_last(t_pipe_data *data, char **envp);
void		execute_middle(t_pipe_data *data, char **envp);

//open_file
void		open_file(t_pipe_data *data);

//util_1
char		*ft_strdupp(const char *s1, size_t n);
size_t		ft_count(const char *s, char c);
char		**free_result(char **list);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);

//util_2
size_t		ft_strlen(const char *s);
void		safe_free(char *object);
int			check_string(char *dst, char *obj);
char		**make_path_2(char **envp);
char		*ft_substr(char const *s, unsigned int start, size_t len);

//util_3
void		free_array(char **array);
void		init_util(t_pipe_data *data, int argc, char **argv, int *index);

#endif
