/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm_hourglass.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:26:46 by susong            #+#    #+#             */
/*   Updated: 2022/09/20 14:44:51 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	hourglass(DoubleList *stack_a, DoubleList *stack_b, int chunk)
{
	if (chunk < 15)
		chunk = 5;
	phase1(stack_a, stack_b, chunk);

	phase2(stack_a, stack_b);
}

void	phase1(DoubleList *stack_a, DoubleList *stack_b, int chunk)
{
	int		pivot;
	t_node	*header;

	pivot = 0;
	header = &stack_a->headerNode;
	while (header->right != header)
	{
		if (header->right->index <= pivot)
		{
			pb(stack_a, stack_b);
			pivot++;
		}
		else if (header->right->index > pivot && \
		header->right->index <= (pivot + chunk))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			pivot++;
		}
		else
			ra(stack_a);
		// printf("NOW pivot is %d\n",pivot);
		// print_stack(stack_b);
	}
}

void	phase2(DoubleList *stack_a, DoubleList *stack_b)
{
	t_node	*header;

	header = &stack_b->headerNode;
	while (header->right != header && stack_b->currentElementCount > 0)
	{
		if (header->right->index > header->left->index)
			pa(stack_a, stack_b);
		else if (stack_b->currentElementCount == 1)
			pa(stack_a, stack_b);
		else
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
		}
	}
}
