/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:49:34 by susong            #+#    #+#             */
/*   Updated: 2022/08/18 17:02:03 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int ft_write_arg(const char *s, va_list *ap)
{
	int length;

	length = 0;
	if (s[1] == '%')
		length += write(1, "%%", 1);
	else if (s[1] == 'c')
		length += ft_print_c(&ap);
	else if (s[1] == 's')
		length += ft_print_s(&ap);
	else if (s[1] == 'p')
		length += ft_print_p(&ap);
	else if (s[1] == 'd')
		length += ft_print_d(&ap);
	else if (s[1] == 'i')
		length += ft_print_i(&ap);
	else if (s[1] == 'u')
		length += ft_print_u(&ap);
	else if (s[1] == 'x')
		length += ft_print_x(&ap);
	else if (s[1] == 'X')
		length += ft_print_X(&ap);
	return (length);
}

int ft_print_c(va_list **ap)
{
	unsigned char temp;
	int print_size;

	print_size = 0;
	temp = (unsigned char)va_arg(**ap, int);
	print_size = write(1, &temp, 1);
	return (print_size);
}

int ft_print_s(va_list **ap)
{
	char *temp;
	int print_size;

	print_size = 0;
	temp = (char *)va_arg(**ap, char *);
	if (!temp)
		print_size = write(1, "(null)", 6);
	else
		print_size = write(1, temp, ft_strlen(temp));
	return (print_size);
}

int ft_print_p(va_list **ap)
{
	int length;
	unsigned int temp;

	temp = (unsigned int)va_arg(**ap, unsigned int);
	length = write(1, "0x", 2);
	if (length == -1)
		return (0);
	if (temp == 0)
	{
		length += write(1, "0", 1);
		return (length);
	}
	length += make_hex(temp, length);
	return (length - 1);
}

int ft_print_d(va_list **ap)
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
