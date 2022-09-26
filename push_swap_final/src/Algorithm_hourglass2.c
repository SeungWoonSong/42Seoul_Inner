/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm_hourglass_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:57:34 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 13:58:36 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_from_top(t_doublelist *stack_a, t_doublelist *stack_b, int depth)
{
	while (depth > 0)
	{
		depth--;
		rb(stack_b);
	}
	pa(stack_a, stack_b);
	return ;
}

void	push_from_bottom(t_doublelist *stack_a, t_doublelist *stack_b,
			int depth)
{
	while (depth > 0)
	{
		depth--;
		rrb(stack_b);
	}
	rrb(stack_b);
	pa(stack_a, stack_b);
	return ;
}
