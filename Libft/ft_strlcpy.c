/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:57:04 by susong            #+#    #+#             */
/*   Updated: 2022/08/06 22:53:04 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t size)
{
	int	i;

	if (!(dest || source))
		return (0);
	i = 0;
	if (size != 0)
	{
		while (source[i] && --size)
		{
			dest[i] = source[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(source));
}
