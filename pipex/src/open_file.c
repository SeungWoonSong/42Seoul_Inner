/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:24:29 by susong            #+#    #+#             */
/*   Updated: 2022/10/04 21:10:16 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void open_file(t_pipe_data *data)
{
	int fd;
	int flag;
	char buf[1024];

	printf("infile is %s\n", data->infile);
	fd = open(data->infile, O_RDONLY | O_EXCL, 0644);
	flag = 1;
	if(fd == -1)
	{
		// Change to exit fuc
		printf("FD ERROR");
	}
	// dup2(fd, data->fd[0][1]);
	// dup2(fd, STD_IN);
	// dup2(data->fd[0][1], STD_OUT);
	// close(fd);
	// close(data->fd[1][1]);
	// close(data->fd[1][0]);
	// close(data->fd[0][0]);
	// close(data->fd[0][1]);
	// dup2(data->fd[0][0], fd);
	// printf("fd is %d\n\n",fd);
	while(flag)
	{
		flag = read(fd, buf, 1024);
		printf("flag is %d\n", flag);
		if(flag == 0 || flag == -1)
			break;
		write(data->fd[0][1], buf, flag);
	}
}
