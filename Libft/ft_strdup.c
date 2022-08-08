/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:42:00 by susong            #+#    #+#             */
/*   Updated: 2022/08/08 12:50:54 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		length;

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
