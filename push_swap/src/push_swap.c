/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:16:33 by susong            #+#    #+#             */
/*   Updated: 2022/09/20 14:03:33 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	DoubleList	*stack_a;
	DoubleList	*stack_b;
	int			*indexed_arr; // 소팅 된 녀석
	int			*arr; // 입력 그대로의 녀석

	indexed_arr = 0;
	if (!make_indexed_arr(&indexed_arr, argc, argv, 1))
		print_error(indexed_arr);
	if (!make_indexed_arr(&arr, argc, argv, 0))
		print_error(indexed_arr);
	stack_a = make_stack_a(argc, indexed_arr, arr);
	stack_b = init_node();
	exec_Algorithm(stack_a, stack_b, argc - 1);
	// sa(stack_a);
	// pb(stack_a,stack_b);
	// pb(stack_a,stack_b);
	// pb(stack_a,stack_b);
	// pa(stack_a,stack_b);
	// pa(stack_a,stack_b);
	// pa(stack_a,stack_b);

	// ra(stack_a);
	// ra(stack_a);

	printf("\n------stack_a size : %d-----\n",stack_a->currentElementCount);
	print_stack(stack_a);
	printf("\n------stack_b size : %d-----\n",stack_b->currentElementCount);
	print_stack(stack_b);
	printf("\n---end---\n");

	// printf("sizeof %d", i);

}

void print_error(int *for_free)
{
	printf("Error\n");
	if (for_free != NULL)
		free(for_free);
	exit(1);
}

void print_stack(DoubleList *stack)
{
	int temp = 0;
	t_node *temp_node;

	temp_node = stack->headerNode.right;
	while(temp < stack->currentElementCount)
	{
		printf("index : %d, data : %d\n", temp_node->index, temp_node->data);
		temp_node = temp_node->right;
		temp++;
	}
	printf("head node %d %d\n\n",temp_node->index, temp_node->data);
	return ;
}
