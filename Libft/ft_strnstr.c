/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:12:24 by susong            #+#    #+#             */
/*   Updated: 2022/08/08 15:50:23 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_size;
	size_t	big_size;

	if (*little == 0)
		return ((char *)big);
	else if (len == 0)
		return (0);
	big_size = ft_strlen(big);
	little_size = ft_strlen(little);
	if (len > big_size)
		len = big_size;
	while (len-- - little_size + 1 && *big)
	{
		if (ft_strncmp(big, little, little_size) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
