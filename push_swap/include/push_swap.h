/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:19:58 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 14:17:40 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node{
	int				index;
	int				data;
	struct t_node	*left;
	struct t_node	*right;

}	t_node;

typedef struct Double_Linked
{
	int		currentelementcount;
	t_node	headernode;
}	t_doublelist;

// parse
int				make_indexed_arr(int **indexed_arr, int argc,
					char **resource, int flag);
int				ft_atoi(const char *str);
int				check_digit(char *check);
int				sort_bubble(int **indexed_arr, int index);
int				check_over_int(char *check);

//Algorithm
void			exec_algorithm(t_doublelist *stack_a,
					t_doublelist *stack_b, int temp);
void			exec_case_2(t_doublelist *stack);
void			exec_case_3(t_doublelist *stack_a, t_doublelist *stack_b);
void			exec_case_4(t_doublelist *stack_a, t_doublelist *stack_b);
void			exec_case_5(t_doublelist *stack_a, t_doublelist *stack_b);
//Algorithm_hourglass
void			hourglass(t_doublelist *stack_a,
					t_doublelist *stack_b, int chunk);
void			phase1(t_doublelist *stack_a, t_doublelist *stack_b, int chunk);
void			phase2(t_doublelist *stack_a, t_doublelist *stack_b);

int				find_depth_top(t_doublelist *stack_b, t_node *present);
int				find_depth_bottom(t_doublelist *stack_b, t_node *present);
void			push_from_top(t_doublelist *stack_a,
					t_doublelist *stack_b, int depth);
void			push_from_bottom(t_doublelist *stack_a,
					t_doublelist *stack_b, int depth);
// main
void			print_error(int *for_free);
void			print_stack(t_doublelist *stack);
void			print_error(int *for_free);
void			print_string(char *string);

//make_node
t_doublelist	*make_stack_a(int index,
					int *indexed_arr, int *arr);
t_doublelist	*init_node(void);
int				add_node_back(t_doublelist *head, int *index_arr, int data);
void			bubble_util(int *dest, int *from);

//operation
void			sa(t_doublelist *stack_a);
void			sb(t_doublelist *stack_a);
void			ss(t_doublelist *stack_a, t_doublelist *stack_b);
void			pa(t_doublelist *stack_b, t_doublelist *stack_a);
void			pb(t_doublelist *stack_a, t_doublelist *stack_b);
void			ra(t_doublelist *stack);
void			rb(t_doublelist *stack);
void			rr(t_doublelist *stack_a, t_doublelist *stack_b);
void			rra(t_doublelist *stack);
void			rrb(t_doublelist *stack);
void			rrr(t_doublelist *stack_a, t_doublelist *stack_b);
#	endif
