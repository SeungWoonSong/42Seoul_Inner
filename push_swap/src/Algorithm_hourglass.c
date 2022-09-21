/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm_hourglass.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:26:46 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 13:57:51 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	hourglass(t_doublelist *stack_a, t_doublelist *stack_b, int chunk)
{
	if (chunk < 15)
		chunk = 5;
	phase1(stack_a, stack_b, chunk);
	phase2(stack_a, stack_b);
}

void	phase1(t_doublelist *stack_a, t_doublelist *stack_b, int chunk)
{
	int		pivot;
	t_node	*header;

	pivot = 0;
	header = &stack_a->headernode;
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

void	phase2(t_doublelist *stack_a, t_doublelist *stack_b)
{
	t_node			*header;
	int				depth_top;
	int				depth_bottom;

	header = &stack_b->headernode;
	while (header->right != header && stack_b->currentelementcount > 0)
	{
		depth_top = find_depth_top(stack_b, header->right);
		depth_bottom = find_depth_bottom(stack_b, header->left);
		if (depth_top < depth_bottom)
			push_from_top(stack_a, stack_b, depth_top);
		else
			push_from_bottom(stack_a, stack_b, depth_bottom);
	}
}

int	find_depth_top(t_doublelist *stack_b, t_node *present)
{
	int	depth;

	depth = 0;
	while (present->index != (stack_b->currentelementcount - 1))
	{
		depth++;
		present = present->right;
	}
	return (depth);
}

int	find_depth_bottom(t_doublelist *stack_b, t_node *present)
{
	int	depth;

	depth = 0;
	while (present->index != (stack_b->currentelementcount - 1))
	{
		depth++;
		present = present->left;
	}
	return (depth);
}
