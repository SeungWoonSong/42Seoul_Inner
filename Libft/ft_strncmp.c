/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:29:14 by susong            #+#    #+#             */
/*   Updated: 2022/08/08 14:57:42 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			length;
	unsigned char	*p1;
	unsigned char	*p2;

	length = -1;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (++length < n)
	{
		if ((p1[length] != p2[length]) || (!(p1[length] && p2[length])))
			return (p1[length] - p2[length]);
	}
	return (0);
}
