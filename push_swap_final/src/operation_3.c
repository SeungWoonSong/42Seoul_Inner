/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:56:48 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 14:59:10 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// rrr : rra and rrb at the same time.

void	rrr(t_doublelist *stack_a, t_doublelist *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	print_string("rrr\n");
}

//bubble sort util
void	bubble_util(int *dest, int *from)
{
	int	temp;

	temp = *dest;
	*dest = *from;
	*from = temp;
}

void	case_3_util_1(t_doublelist *stack_a)
{
	t_node	*head;

	head = &stack_a->headernode;
	if (head->right->index < head->left->index
		&& head->left->index > head->right->right->index
		&& head->right->index > head->right->right->index)
		sa(stack_a);
	else if (head->right->index > head->left->index
		&& head->left->index < head->right->right->index
		&& head->right->index < head->right->right->index)
		rra(stack_a);
	else if (head->right->index > head->left->index
		&& head->left->index > head->right->right->index
		&& head->right->index > head->right->right->index)
		ra(stack_a);
	return ;
}

void	case_3_util_2(t_doublelist *stack_a)
{
	t_node	*head;

	head = &stack_a->headernode;
	if (head->right->index > head->left->index
		&& head->left->index < head->right->right->index
		&& head->right->index > head->right->right->index)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->right->index < head->left->index
		&& head->left->index < head->right->right->index
		&& head->right->index < head->right->right->index)
	{
		sa(stack_a);
		ra(stack_a);
	}
	return ;
}
