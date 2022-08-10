/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:24:27 by susong            #+#    #+#             */
/*   Updated: 2022/08/10 11:47:50 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		free(list[i]);
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
