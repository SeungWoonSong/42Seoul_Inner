/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:57:45 by susong            #+#    #+#             */
/*   Updated: 2022/08/19 15:49:30 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		index;
	int		print_size;
	int		past_size;

	print_size = 0;
	index = 0;
	va_start(ap, s);
	while (s[index])
	{
		past_size = print_size;
		if (s[index] != '%')
			print_size += write(1, &s[index], 1);
		else
			print_size += ft_write_arg(&s[index++], &ap);
		index++;
		if (past_size > print_size)
		{
			va_end(ap);
			return (-1);
		}
	}
	va_end(ap);
	return (print_size);
}
