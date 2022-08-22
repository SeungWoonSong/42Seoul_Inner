/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:46:59 by nouswong          #+#    #+#             */
/*   Updated: 2022/08/22 17:04:41 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_and_join(int fd, char *backup)
{
}
char *get_next_line(int fd)
{
	static char backup[BUFFER_SIZE + 1];
	char Buffer_now[BUFFER_SIZE + 1];
	char *result;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// 만약 backup에 개행이 있다면? -> 그전까지 리턴, 없으면 read 실시
	// if (ft_strchr(backup, '\n'))
	// 	result = ft_strdup(backup [0:'\n'있는 곳])
	// 	while (!(ft_strchr(result, '\n')))
	//  	result = readjoin(fd,backup );
	//  backup = result 개행 후
	//	return(개행 전까지!)
	// //
}

int main()
{

	int fd = fopen("./ test.txt", "r");
	for (int i = 0; i < 4; i++)
	{
		get_next_line(fd);
	}
}