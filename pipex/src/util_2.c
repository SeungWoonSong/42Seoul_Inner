/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:22:39 by susong            #+#    #+#             */
/*   Updated: 2022/10/02 16:15:29 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

void	safe_free(char *object)
{
	if(object)
		free(object);
	return ;
}

// check where is obj in dst
int		check_string(char *dst, char *obj)
{
	int index;
	int index_obj;

	index = 0;
	while(dst[index + ft_strlen(obj)])
	{
		index_obj = 0;
		while(dst[index + index_obj] == obj[index_obj])
			index_obj += 1;
		if(index_obj == ft_strlen(obj))
			return(1);
		index++;
	}
	return(0);
}

char **make_path_2(char **envp)
{
	int index;
	char *temp;
	char **result;

	index = 0;
	while(envp[index])
		index++;
	result = (char **)malloc(sizeof(char *) * (index + 1));
	result[index] = 0;
	index = 0;
	while(envp[index])
	{
		result[index] = ft_strjoin(envp[index], "/");
		index++;
	}
	return(result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!(result))
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			result[j] = s[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}
