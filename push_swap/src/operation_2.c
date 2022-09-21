/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:06:15 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 13:57:07 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ra(t_doublelist *stack)
{
	t_node	*temp;

	if (stack->currentelementcount <= 1)
		return ;
	temp = stack->headernode.right;
	stack->headernode.right = temp->right;
	temp->right->left = &stack->headernode;
	stack->headernode.left->right = temp;
	temp->left = stack->headernode.left;
	stack->headernode.left = temp;
	temp->right = &stack->headernode;
	print_string("ra\n");
}
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

void	rb(t_doublelist *stack)
{
	t_node	*temp;

	if (stack->currentelementcount <= 1)
		return ;
	temp = stack->headernode.right;
	stack->headernode.right = temp->right;
	temp->right->left = &stack->headernode;
	stack->headernode.left->right = temp;
	temp->left = stack->headernode.left;
	stack->headernode.left = temp;
	temp->right = &stack->headernode;
	print_string("rb\n");
}
// rr : ra and rb at the same time.

void	rr(t_doublelist *stack_a, t_doublelist *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	print_string("rr\n");
}
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

void	rra(t_doublelist *stack)
{
	t_node	*temp;

	temp = stack->headernode.left;
	stack->headernode.left = temp->left;
	stack->headernode.left->right = &stack->headernode;
	temp->right = stack->headernode.right;
	temp->right->left = temp;
	temp->left = &stack->headernode;
	stack->headernode.right = temp;
	print_string("rra\n");
}
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

void	rrb(t_doublelist *stack)
{
	t_node	*temp;

	temp = stack->headernode.left;
	stack->headernode.left = temp->left;
	stack->headernode.left->right = &stack->headernode;
	temp->right = stack->headernode.right;
	temp->right->left = temp;
	temp->left = &stack->headernode;
	stack->headernode.right = temp;
	print_string("rrb\n");
}
