/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:06:15 by susong            #+#    #+#             */
/*   Updated: 2022/09/20 12:09:47 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	sa(DoubleList *stack_a)
{
	t_node	*temp;

	temp = stack_a->headerNode.right;
	if (temp == &stack_a->headerNode)
		return ;
	stack_a->headerNode.right = temp->right;
	temp->right->left = &stack_a->headerNode;
	temp->right = stack_a->headerNode.right->right;
	stack_a->headerNode.right->right = temp;
	temp->right->left = temp;
	temp->left = stack_a->headerNode.right;
	printf("sa\n");
}
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(DoubleList *stack_a)
{
	t_node	*temp;

	temp = stack_a->headerNode.right;
	if (temp == &stack_a->headerNode)
		return ;
	stack_a->headerNode.right = temp->right;
	temp->right->left = &stack_a->headerNode;
	temp->right = stack_a->headerNode.right->right;
	stack_a->headerNode.right->right = temp;
	temp->right->left = temp;
	temp->left = stack_a->headerNode.right;
	printf("sb\n");
}
// ss : sa and sb at the same time.
void	ss(DoubleList *stack_a, DoubleList *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss");
}
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(DoubleList *stack_b, DoubleList *stack_a)
{
	t_node	*temp;

	if (stack_a->currentElementCount < 1 || stack_b->currentElementCount < 0)
		return ;
	temp = stack_a->headerNode.right;
	stack_a->headerNode.right = temp->right;
	temp->right->left = &stack_a->headerNode;
	if (stack_b->currentElementCount > 0)
	{
		stack_b->headerNode.right->left = temp;
		temp->right = stack_b->headerNode.right;
		stack_b->headerNode.right = temp;
		temp->left = &stack_b->headerNode;
	}
	else
	{
		stack_b->headerNode.right = temp;
		stack_b->headerNode.left = temp;
		temp->left = &stack_b->headerNode;
		temp->right = &stack_b->headerNode;
	}
	stack_b->currentElementCount += 1;
	stack_a->currentElementCount -= 1;
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

void	pb(DoubleList *stack_a, DoubleList *stack_b)
{
	t_node	*temp;

	if (stack_a->currentElementCount < 1 || stack_b->currentElementCount < 0)
		return ;
	temp = stack_a->headerNode.right;
	stack_a->headerNode.right = temp->right;
	temp->right->left = &stack_a->headerNode;
	if (stack_b->currentElementCount > 0)
	{
		stack_b->headerNode.right->left = temp;
		temp->right = stack_b->headerNode.right;
		stack_b->headerNode.right = temp;
		temp->left = &stack_b->headerNode;
	}
	else if(stack_b->currentElementCount == 0)
	{
		stack_b->headerNode.right = temp;
		stack_b->headerNode.left = temp;
		temp->left = &stack_b->headerNode;
		temp->right = &stack_b->headerNode;

	}
	stack_b->currentElementCount += 1;
	stack_a->currentElementCount -= 1;
}


// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

void	ra(DoubleList *stack)
{
	t_node *temp;

	if (stack->currentElementCount <= 1)
		return ;
	temp = stack->headerNode.right;
	printf("temp data %d %d\n", temp->data, temp->index);
	stack->headerNode.right = temp->right;
	temp->right->left = &stack->headerNode;
	stack->headerNode.left->right = temp;
	temp->left = stack->headerNode.left;
	stack->headerNode.left = temp;
	temp->right = &stack->headerNode;
	printf("ra\n");
}
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(DoubleList *stack)
{
	t_node *temp;

	if (stack->currentElementCount <= 1)
		return ;
	temp = stack->headerNode.right;
	stack->headerNode.right = temp->right;
	temp->right->left = &stack->headerNode;
	stack->headerNode.left->right = temp;
	temp->left = stack->headerNode.left;
	stack->headerNode.left = temp;
	temp->right = &stack->headerNode;
	printf("rb\n");
}
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.
