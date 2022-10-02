/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:59:49 by susong            #+#    #+#             */
/*   Updated: 2022/10/02 15:29:14 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// ft_split, ft_count, ft_strjoin

char	*ft_strdupp(const char *s1, size_t n)
{
	char	*result;
	size_t	length;

	length = 0;
	if (n == 0)
		return (NULL);
	result = (char *)malloc(n + 1);
	if (!result)
		return (0);
	while (length < n)
	{
		result[length] = s1[length];
		length++;
	}
	result[length] = '\0';
	return (result);
}

size_t	ft_count(const char *s, char c)
{
	int		i;
	size_t	result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || \
		(s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			result++;
		i++;
	}
	return (result);
}

char	**free_result(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		safe_free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	sidx;
	size_t	resindx;
	size_t	delimeter;

	sidx = 0;
	resindx = 0;
	delimeter = 0;
	result = (char **)malloc(sizeof(char **) * (ft_count(s, c) + 1));
	if (!result)
		return (0);
	while (resindx < ft_count(s, c) && s[sidx] != '\0')
	{
		while (s[sidx] == c)
			sidx++;
		delimeter = sidx;
		while (s[sidx] != c && s[sidx] != '\0')
			sidx++;
		result[resindx] = ft_strdupp(&s[delimeter], sidx - delimeter);
		if (result[resindx++] == 0)
			return (free_result(result));
	}
	result[resindx] = NULL;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		length;

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
