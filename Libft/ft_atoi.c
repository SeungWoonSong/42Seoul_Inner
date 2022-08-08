/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:52:50 by susong            #+#    #+#             */
/*   Updated: 2022/08/08 16:11:01 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	length;

	length = 0;
	result = 0;
	if (!str)
		return (0);
	while (length++ < ft_strlen(str))
	{
		result = result * 10 + (str[length - 1] - 48);
	}
	return (result);
}
