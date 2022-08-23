/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:46:59 by nouswong          #+#    #+#             */
/*   Updated: 2022/08/23 14:45:26 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *absolute_enter(int fd, char *BUFFER, char *backup)
{
	int line_numb;
	char *temp;

	line_numb = 1;
	while (line_numb != '\0')
	{
		line_numb = read(fd, BUFFER, BUFFER_SIZE);
		if (line_numb < 0)
			return (0);
		else if (line_numb == 0)
			break;
		BUFFER[line_numb] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, BUFFER);
		free(temp);
		if (ft_strchr(backup, '\n'))
			break;
	}
	return (backup);
}

char *extract_result(char *result, char *backup)
{
	int count;

	count = 0;
	while (result[count] != '\n' && result[count] != '\0')
		count++;
	if (result[count] != '\n' && result[count] != '\0')
		return (0);
	backup = ft_substr(result, count + 1, ft_strlen(result) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	result[count + 1] = '\0';
	return (backup);
}

char *get_next_line(int fd)
{
	static char *backup;
	char Buffer_now[BUFFER_SIZE + 1];
	char *result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = absolute_enter(fd, Buffer_now, backup);
	if (!result)
		return (NULL);
	backup = extract_result(result, backup);
	return (result);
	// 만약 backup에 개행이 있다면? -> 그전까지 리턴, 없으면 read 실시
	// if (ft_strchr(backup, '\n'))
	// 	result = ft_strdup(backup [0:'\n'있는 곳])
	// 	while (!(ft_strchr(result, '\n')))
	//  	result = readjoin(fd,backup );
	//  backup = result 개행 후
	//	return(개행 전까지!)
	// //
}

// int main()
// {

// 	int fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	while (1)
// 	{
// 	}
// }