/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:06:14 by susong            #+#    #+#             */
/*   Updated: 2022/08/10 20:35:08 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!(dest && source))
		return (dest);
	a = (unsigned char *)dest;
	b = (unsigned char *)source;
	if (dest > source)
	{
		while (n--)
			*(a + n) = *(b + n);
	}
	else
	{
		while (n--)
			*a++ = *b++;
	}
	return (dest);
}
