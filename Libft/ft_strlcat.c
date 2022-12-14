/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:51:04 by susong            #+#    #+#             */
/*   Updated: 2022/08/08 14:12:00 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int	dst_len;
	int	src_len;
	int	result;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	result = dst_len + src_len;
	if (dst_len >= (int)size)
		return (src_len + (int)size);
	else if ((int)size < src_len + dst_len + 1)
	{
		src_len = size - dst_len - 1;
		if (src_len < 0)
			src_len = 0;
	}
	while ((dst_len < result) && src_len--)
		dest[dst_len++] = *(src++);
	dest[dst_len] = '\0';
	return (result);
}
