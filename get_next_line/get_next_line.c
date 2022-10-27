/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:46:59 by nouswong          #+#    #+#             */
/*   Updated: 2022/09/29 13:17:03 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*absolute_enter(int fd, char *BUFFER, char *backup)
{
	int		line_numb;
	char	*temp;

	line_numb = 1;
	while (line_numb != '\0')
	{
		line_numb = read(fd, BUFFER, BUFFER_SIZE);
		if (line_numb < 0)
			return (0);
		else if (line_numb == 0)
			break ;
		BUFFER[line_numb] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, BUFFER);
		free(temp);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

char	*extract_result(char *result, char *backup)
{
	int	count;

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

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buffernow[BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = absolute_enter(fd, buffernow, backup);
	if (!result)
		return (NULL);
	backup = extract_result(result, backup);
	return (result);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char* tmp = NULL;
	while (tmp = get_next_line(fd)) {
		printf("%s", tmp);
		free(tmp);
	}
}
