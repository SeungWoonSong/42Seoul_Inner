/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:46:54 by nouswong          #+#    #+#             */
/*   Updated: 2022/08/23 15:13:36 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *result;
	int length;

	length = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (0);
	while (s1 && *s1)
		*result++ = *s1++;
	while (s2 && *s2)
		*result++ = *s2++;
	*result = '\0';
	result -= length;
	return (result);
}

char *ft_strdup(const char *s1)
{
	char *result;
	int length;

	length = 0;
	result = malloc(ft_strlen(s1) + 1);
	if (!result)
		return (0);
	while (s1 && s1[length])
	{
		result[length] = s1[length];
		length++;
	}
	result[length] = '\0';
	return (result);
}

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

size_t ft_strlen(const char *s)
{
	size_t length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *result;
	size_t i;
	size_t j;

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