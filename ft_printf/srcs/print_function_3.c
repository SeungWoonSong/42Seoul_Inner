/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:45:41 by susong            #+#    #+#             */
/*   Updated: 2022/08/18 16:45:59 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int make_hex2(unsigned int p, int length)
{
	unsigned char temp;

	temp = p % 16;
	if (p / 16 > 0)
		length = make_hex2(p / 16, length);
	if (temp >= 10)
	{
		temp += ('A' - 10);
		write(1, &temp, 1);
	}
	else
	{
		temp += '0';
		write(1, &temp, 1);
	}
	return (length + 1);
}
