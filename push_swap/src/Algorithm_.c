/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:01:57 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 10:21:09 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void exec_Algorithm(DoubleList *stack_a, DoubleList *stack_b, int temp)
{
	int	chunk;

	chunk = (int)(0.000000053 * (temp * temp) + 0.03 * temp + 14.5);
	if (temp > 5)
		hourglass(stack_a, stack_b, chunk);
	else if (temp == 5)
		exec_case_5(stack_a, stack_b);
	else if (temp == 4)
		exec_case_4(stack_a, stack_b);
	else if (temp == 3)
		exec_case_3(stack_a, stack_b);
	else if (temp == 2)
		exec_case_2(stack_a, stack_b);
}

void exec_case_2(DoubleList *stack_a, DoubleList *stack_b)
{

}

void exec_case_3(DoubleList *stack_a, DoubleList *stack_b)
{

}
void exec_case_4(DoubleList *stack_a, DoubleList *stack_b)
{

}
void exec_case_5(DoubleList *stack_a, DoubleList *stack_b)
{

}
