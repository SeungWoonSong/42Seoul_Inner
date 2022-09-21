/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:06:06 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 13:56:20 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	sa(t_doublelist *stack_a)
{
	t_node	*temp;

	temp = stack_a->headernode.right;
	if (temp == &stack_a->headernode)
		return ;
	stack_a->headernode.right = temp->right;
	temp->right->left = &stack_a->headernode;
	temp->right = stack_a->headernode.right->right;
	stack_a->headernode.right->right = temp;
	temp->right->left = temp;
	temp->left = stack_a->headernode.right;
	print_string("sa\n");
}

void	sb(t_doublelist *stack_a)
{
	t_node	*temp;

	temp = stack_a->headernode.right;
	if (temp == &stack_a->headernode)
		return ;
	stack_a->headernode.right = temp->right;
	temp->right->left = &stack_a->headernode;
	temp->right = stack_a->headernode.right->right;
	stack_a->headernode.right->right = temp;
	temp->right->left = temp;
	temp->left = stack_a->headernode.right;
	print_string("sb\n");
}
// ss : sa and sb at the same time.

void	ss(t_doublelist *stack_a, t_doublelist *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	print_string("ss");
}
// pa (push a): Take the first element at
// the top of b and put it at the top of a.
// Do nothing if b is empty.

void	pa(t_doublelist *stack_b, t_doublelist *stack_a)
{
	t_node	*temp;

	if (stack_a->currentelementcount < 1 || stack_b->currentelementcount < 0)
		return ;
	temp = stack_a->headernode.right;
	stack_a->headernode.right = temp->right;
	temp->right->left = &stack_a->headernode;
	if (stack_b->currentelementcount > 0)
	{
		stack_b->headernode.right->left = temp;
		temp->right = stack_b->headernode.right;
		stack_b->headernode.right = temp;
		temp->left = &stack_b->headernode;
	}
	else
	{
		stack_b->headernode.right = temp;
		stack_b->headernode.left = temp;
		temp->left = &stack_b->headernode;
		temp->right = &stack_b->headernode;
	}
	stack_b->currentelementcount += 1;
	stack_a->currentelementcount -= 1;
	print_string("pa\n");
}

// pb (push b): Take the first element at
//the top of a and put it at the top of b.
// Do nothing if a is empty.

void	pb(t_doublelist *stack_a, t_doublelist *stack_b)
{
	t_node	*temp;

	if (stack_a->currentelementcount < 1 || stack_b->currentelementcount < 0)
		return ;
	temp = stack_a->headernode.right;
	stack_a->headernode.right = temp->right;
	temp->right->left = &stack_a->headernode;
	if (stack_b->currentelementcount > 0)
	{
		stack_b->headernode.right->left = temp;
		temp->right = stack_b->headernode.right;
		stack_b->headernode.right = temp;
		temp->left = &stack_b->headernode;
	}
	else if (stack_b->currentelementcount == 0)
	{
		stack_b->headernode.right = temp;
		stack_b->headernode.left = temp;
		temp->left = &stack_b->headernode;
		temp->right = &stack_b->headernode;
	}
	stack_b->currentelementcount += 1;
	stack_a->currentelementcount -= 1;
	print_string("pb\n");
}
