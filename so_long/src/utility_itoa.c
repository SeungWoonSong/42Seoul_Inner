/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:57:49 by susong            #+#    #+#             */
/*   Updated: 2022/09/26 09:26:29 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*plusorminus(char *result, long n)
{
	if (n < 0)
		result = (char *)malloc(sizeof(char) * (ft_count(n) + 2));
	else if (n > 0)
		result = (char *)malloc(sizeof(char) * (ft_count(n) + 1));
	else
	{
		result = (char *)malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (!result)
		return (0);
	if (n < 0)
	{
		result[0] = '-';
		result[ft_count(n) + 1] = '\0';
	}
	else
		result[ft_count(n)] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		index;
	int		temp;
	long	n2;

	result = 0;
	n2 = (long)n;
	result = plusorminus(result, n2);
	if (!result)
		return (0);
	if (n2 == 0)
		return (result);
	if (n2 < 0)
		index = ft_count(n2);
	else
		index = ft_count(n2) - 1;
	if (n2 < 0)
		n2 = n2 * -1;
	temp = ft_count(n2);
	while (temp-- > 0)
	{
		result[index--] = n2 % 10 + '0';
		n2 = n2 / 10;
	}
	return (result);
}
