/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:01:57 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 14:59:43 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exec_algorithm(t_doublelist *stack_a, t_doublelist *stack_b, int temp)
{
	int	chunk;

	chunk = (int)(0.000000053 * (temp * temp) + 0.03 * temp + 14.5);
	if (temp > 5 || temp == 4)
		hourglass(stack_a, stack_b, chunk);
	else if (temp == 5)
		exec_case_5(stack_a, stack_b);
	else if (temp == 3)
		exec_case_3(stack_a);
	else if (temp == 2)
		exec_case_2(stack_a);
}

void	exec_case_2(t_doublelist *stack)
{
	if (stack->headernode.right->index > stack->headernode.left->index)
		sa(stack);
	return ;
}

void	exec_case_3(t_doublelist *stack_a)
{
	case_3_util_1(stack_a);
	case_3_util_2(stack_a);
	return ;
}

void	exec_case_5(t_doublelist *stack_a, t_doublelist *stack_b)
{
	int	counter;

	counter = 0;
	while (counter < 2)
	{
		if (stack_a->headernode.right->index == 0
			|| stack_a->headernode.right->index == 1)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
	exec_case_3(stack_a);
	if (stack_b->headernode.right->index < stack_b->headernode.left->index)
		rb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	return ;
}
