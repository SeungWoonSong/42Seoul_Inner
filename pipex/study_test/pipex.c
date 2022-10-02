/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:16:38 by susong            #+#    #+#             */
/*   Updated: 2022/09/27 10:14:30 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main()
{
	int fd[2];

	pipe(fd);
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input number : ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		y = y * 100;
		printf("%d", y);
		close(fd[0]);
	}
}
