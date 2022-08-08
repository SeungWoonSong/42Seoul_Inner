/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:30:11 by susong            #+#    #+#             */
/*   Updated: 2022/08/08 12:41:22 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*result1;
	unsigned char	*result2;

	result1 = (unsigned char *)s1;
	result2 = (unsigned char *)s2;
	while (n--)
	{
		if (*result1++ != *result2++)
			return (*--result1 - *--result2);
	}
	return (0);
}
