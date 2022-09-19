/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:16:33 by susong            #+#    #+#             */
/*   Updated: 2022/09/19 18:04:46 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_Node	*stack_a;
	t_Node	*stack_b;
	int		*indexed_arr;

	indexed_arr = 0;
	if(!make_indexed_arr(&indexed_arr, argc, argv))
		printf("Error");
		//TODO : indexed arr free
	// init_stack(stack_a, stack_b);
	// make_stack_a(stack_a);

	int i;
	i = 0;
	while(indexed_arr[i]){
		printf("\n%d is %d", i, indexed_arr[i]);
		i++;
	}

	// printf("sizeof %d", i);

}
