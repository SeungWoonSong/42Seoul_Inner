/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:16:33 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 14:09:35 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_doublelist	*stack_a;
	t_doublelist	*stack_b;
	int				*indexed_arr;
	int				*arr;

	indexed_arr = 0;
	if (!make_indexed_arr(&indexed_arr, argc, argv, 1))
		print_error(indexed_arr);
	if (!make_indexed_arr(&arr, argc, argv, 0))
		print_error(indexed_arr);
	stack_a = make_stack_a(argc, indexed_arr, arr);
	stack_b = init_node();
	exec_algorithm(stack_a, stack_b, argc - 1);
	return (0);
}

void	print_error(int *for_free)
{
	write(2, "Error\n", 6);
	if (for_free != NULL)
		free(for_free);
	exit(0);
}

void	print_string(char *string)
{
	int	size;

	size = 0;
	if (!string)
		return ;
	while (string[size])
		size++;
	write(1, string, size);
}
