/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 21:27:51 by susong            #+#    #+#             */
/*   Updated: 2022/08/06 21:32:59 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	*p;

	p = (char *)s;
	length = ft_strlen(p);
	while (length >= 0)
	{
		if (s[length] == (char)c)
			return (p + length);
		length--;
	}
	return (NULL);
}
