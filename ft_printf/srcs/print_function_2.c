/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:49:48 by susong            #+#    #+#             */
/*   Updated: 2022/08/18 17:03:32 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int ft_print_i(va_list **ap)
{
	int length;
	char *temp;
	int numtemp;

	length = 0;
	numtemp = (int)va_arg(**ap, int);
	if (numtemp == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	temp = ft_itoa(numtemp);
	length += write(1, temp, ft_strlen(temp));
	free(temp);
	return (length);
}

int ft_print_u(va_list **ap)
{
	int length;
	char *temp;
	unsigned int numtemp;

	length = 0;
	numtemp = (unsigned int)va_arg(**ap, unsigned int);
	if (numtemp == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	temp = ft_itoa_long(numtemp);
	length += write(1, temp, ft_strlen(temp));
	free(temp);
	return (length);
}

int ft_print_x(va_list **ap)
{
	int length;
	unsigned int temp;

	length = 0;
	temp = (unsigned int)va_arg(**ap, unsigned int);
	length += make_hex(temp, length);
	return (length);
}

int ft_print_X(va_list **ap)
{
	int length;
	unsigned int temp;

	length = 0;
	temp = (unsigned int)va_arg(**ap, unsigned int);
	length += make_hex2(temp, length);
	return (length);
}

int make_hex(unsigned int p, int length)
{
	unsigned char temp;
	temp = p % 16;
	if (p / 16 > 0)
		length = make_hex(p / 16, length);
	if (temp >= 10)
	{
		temp += ('a' - 10);
		write(1, &temp, 1);
	}
	else
	{
		temp += '0';
		write(1, &temp, 1);
	}
	return (length + 1);
}
