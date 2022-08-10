/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:02:59 by susong            #+#    #+#             */
/*   Updated: 2022/08/10 15:58:34 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_letter(char a, const char *b)
{
	int	index;

	index = 0;
	while (b[index] != '\0')
	{
		if (b[index] == a)
			return (1);
		index++;
	}
	return (0);
}

int	find_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (find_letter(s1[i], set) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	find_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (find_letter(s1[i], set) == 0)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*result;
	int		temp;

	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start == -1 || end == -1)
	{
		result = (char *)malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	temp = 0;
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (NULL);
	while (start <= end)
		result[temp++] = s1[start++];
	result[temp] = '\0';
	return (result);
}
