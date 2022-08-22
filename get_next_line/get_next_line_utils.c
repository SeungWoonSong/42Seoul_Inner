/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:46:54 by nouswong          #+#    #+#             */
/*   Updated: 2022/08/22 16:48:23 by nouswong         ###   ########.fr       */
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

size_t ft_strlcpy(char *dest, const char *source, size_t size)
{
	int i;

	if (!(dest || source))
		return (0);
	i = 0;
	if (size != 0)
	{
		while (source[i] && --size)
		{
			dest[i] = source[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(source));
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