/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:23:12 by susong            #+#    #+#             */
/*   Updated: 2022/08/12 17:11:07 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!(dest || source))
		return (dest);
	a = (unsigned char *)dest;
	b = (unsigned char *)source;
	while (n--)
		*a++ = *b++;
	return (dest);
}
