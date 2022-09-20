/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:19:58 by susong            #+#    #+#             */
/*   Updated: 2022/09/20 11:56:37 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct t_node{
	int				index;
	int				data;
	struct t_node	*left;
	struct t_node	*right;

}	t_node;

typedef struct Double_Linked
{
	int		currentElementCount;
	t_node	headerNode;
}	DoubleList;

// parse
int	make_indexed_arr(int **indexed_arr, int argc, char **resource, int flag);
int	ft_atoi(const char *str);
int	check_digit(char *check);
int	sort_bubble(int **indexed_arr, int index);

// main
void print_error(int *for_free);
void print_stack(DoubleList *stack);

//make_node
DoubleList	*make_stack_a(int index, int *indexed_arr, int *arr);
DoubleList	*init_node(void);

//operation
void	sa(DoubleList *stack_a);
void	sb(DoubleList *stack_a);
void	ss(DoubleList *stack_a, DoubleList *stack_b);
void	pa(DoubleList *stack_b, DoubleList *stack_a);
void	pb(DoubleList *stack_a, DoubleList *stack_b);
void	ra(DoubleList *stack);
void	rb(DoubleList *stack);
#	endif
