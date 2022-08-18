/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:19:24 by susong            #+#    #+#             */
/*   Updated: 2022/08/18 16:46:09 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_print_c(va_list **ap);
int		ft_print_s(va_list **ap);
int		ft_print_p(va_list **ap);
int		ft_print_d(va_list **ap);
int		ft_print_i(va_list **ap);
int		ft_print_u(va_list **ap);
int		ft_print_x(va_list **ap);
int		ft_print_X(va_list **ap);
int		ft_write_arg(const char *s, va_list *ap);
int		make_hex(int p, int length);
int		make_hex2(int p, int length);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);



#endif