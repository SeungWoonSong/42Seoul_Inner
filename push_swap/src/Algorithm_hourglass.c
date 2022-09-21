/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm_hourglass.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:26:46 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 10:21:41 by susong           ###   ########.fr       */
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
	}
}

void	phase2(DoubleList *stack_a, DoubleList *stack_b)
{
	t_node			*header;
	int				depth_top;
	int				depth_bottom;

	header = &stack_b->headerNode;
	while (header->right != header && stack_b->currentElementCount > 0)
	{
		// printf("stack_b size is %d\n\n",stack_b->currentElementCount);
		depth_top = find_depth_top(stack_b, header->right);
		depth_bottom = find_depth_bottom(stack_b, header->left);
		// printf("depth is %d %d\n",depth_top,depth_bottom);
		if(depth_top < depth_bottom)
			push_from_top(stack_a, stack_b, depth_top);
		else
			push_from_bottom(stack_a, stack_b, depth_bottom);
	}
}

int	find_depth_top(DoubleList *stack_b, t_node *present)
{
	int	depth;

	depth = 0;
	while (present->index != (stack_b->currentElementCount - 1))
	{
		depth++;
		present = present->right;
	}
	return (depth);
}

int	find_depth_bottom(DoubleList *stack_b, t_node *present)
{
	int	depth;

	depth = 0;
	while (present->index != (stack_b->currentElementCount - 1))
	{
		depth++;
		present = present->left;
	}
	return (depth);
}

void	push_from_top(DoubleList *stack_a, DoubleList *stack_b, int depth)
{
	while (depth > 0)
	{
		depth--;
		rb(stack_b);
	}
	pa(stack_a, stack_b);
	return ;
}

void	push_from_bottom(DoubleList *stack_a, DoubleList *stack_b, int depth)
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
