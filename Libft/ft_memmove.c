/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:06:14 by susong            #+#    #+#             */
/*   Updated: 2022/08/06 21:10:55 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!(dest || source))
		return (dest);
	a = (unsigned char *)dest;
	b = (unsigned char *)source;
	if (dest - source < 0)
	{
		while (n--)
			*(a + n - 1) = *(b + n - 1);
		return (dest);
	}
	else
	{
		while (n--)
			*a++ = *b++;
		return (dest);
	}
}
