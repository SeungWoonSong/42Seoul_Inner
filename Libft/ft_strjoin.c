/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:49:52 by susong            #+#    #+#             */
/*   Updated: 2022/08/08 17:02:11 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
