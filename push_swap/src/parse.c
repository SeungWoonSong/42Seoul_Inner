/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:17:39 by susong            #+#    #+#             */
/*   Updated: 2022/09/19 17:28:43 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	if (!str)
		return (0);
	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - 48);
	return (result * sign);
}


int	check_over_int(char *check)
{
	unsigned long long	result;
	int					flag;
	int					i;

	i = 0;
	result = 0;
	flag = 1;
	if (check[i] == '-')
	{
		flag = -1;
		i++;
	}
	while (check[i] >= '0' && check[i] <= '9')
	{
		result = result * 10 + check[i] - '0';
		i++;
	}
	if ((flag == 1 && result > 2147483647) || \
	(flag == -1 && result > 2147483648))
		return (1);
	return (0);
}

// check it is digit or int
int	check_digit(char *check)
{
	int	i;

	i = 0;
	while ((*check >= 9 && *check <= 13) || *check == 32)
		check++;
	while (check[i] != 0)
	{
		if (!(check[i] >= '0' && check[i] <= '9') && check[i] != '-')
			return (0);
		i++;
	}
	if (i >= 10 && check_over_int(check))
		return (0);
	return (1);
}

void	sort_bubble(int **indexed_arr)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while ((*indexed_arr)[i])
	{
		j = i + 1;
		while ((*indexed_arr)[j])
		{
			if ((*indexed_arr)[j] < (*indexed_arr)[i])
			{
				temp = (*indexed_arr)[j];
				(*indexed_arr)[j] = (*indexed_arr)[i];
				(*indexed_arr)[i] = temp;
			}
		j++;
		}
	i++;
	}
}
// something went go wrong return 0, else 1

int	make_indexed_arr(int **indexed_arr, int argc, char **resource)
{
	int	i;

	i = 1;
	*indexed_arr = (int *)malloc(sizeof(int) * argc);
	if (!(*indexed_arr))
		return (0);
	(*indexed_arr)[argc - 1] = 0;
	while (i < argc)
	{
		if (!(check_digit(resource[i])))
			return (0);
		(*indexed_arr)[i - 1] = ft_atoi(resource[i]);
		i++;
	}
	sort_bubble(indexed_arr);
	return (1);
}
