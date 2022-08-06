/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:57:04 by susong            #+#    #+#             */
/*   Updated: 2022/08/06 19:50:46 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t size)
{
	int	i;

	i = 0;
	if (!(dest || source))
		return (0);
	if (size != 0){
		while (dest[i] && size--)
		{
			dest[i] = source[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(source));
}
