/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:56:48 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 14:20:32 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// rrr : rra and rrb at the same time.

void	rrr(t_doublelist *stack_a, t_doublelist *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	print_string("rrr");
}

//bubble sort util
void	bubble_util(int *dest, int *from)
{
	int	temp;

	temp = *dest;
	*dest = *from;
	*from = temp;
}
