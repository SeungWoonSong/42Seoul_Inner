/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:19:58 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 10:13:30 by susong           ###   ########.fr       */
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
int	check_over_int(char *check);

//Algorithm
void exec_Algorithm(DoubleList *stack_a, DoubleList *stack_b, int temp);
void exec_case_2(DoubleList *stack_a, DoubleList *stack_b);
void exec_case_3(DoubleList *stack_a, DoubleList *stack_b);
void exec_case_4(DoubleList *stack_a, DoubleList *stack_b);
void exec_case_5(DoubleList *stack_a, DoubleList *stack_b);
//Algorithm_hourglass
void hourglass(DoubleList *stack_a,DoubleList * stack_b, int chunk);
void phase1(DoubleList *stack_a, DoubleList *stack_b, int chunk);
void phase2(DoubleList *stack_a, DoubleList *stack_b);

int	find_depth_top(DoubleList *stack_b, t_node *present);
int	find_depth_bottom(DoubleList *stack_b, t_node *present);
void	push_from_top(DoubleList *stack_a, DoubleList *stack_b, int depth);
void	push_from_bottom(DoubleList *stack_a, DoubleList *stack_b, int depth);
// main
void print_error(int *for_free);
void print_stack(DoubleList *stack);

//make_node
DoubleList	*make_stack_a(int index, int *indexed_arr, int *arr);
DoubleList	*init_node(void);
int			add_node_back(DoubleList *head, int *index_arr, int data);

//operation
void	sa(DoubleList *stack_a);
void	sb(DoubleList *stack_a);
void	ss(DoubleList *stack_a, DoubleList *stack_b);
void	pa(DoubleList *stack_b, DoubleList *stack_a);
void	pb(DoubleList *stack_a, DoubleList *stack_b);
void	ra(DoubleList *stack);
void	rb(DoubleList *stack);
void	rr(DoubleList *stack_a, DoubleList *stack_b);
void	rra(DoubleList *stack);
void	rrb(DoubleList *stack);
void	rrr(DoubleList *stack_a, DoubleList * stack_b);
#	endif
