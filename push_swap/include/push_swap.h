/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:19:58 by susong            #+#    #+#             */
/*   Updated: 2022/09/19 17:00:10 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int				index;
	int				data;
	struct t_Node	*left;
	struct t_Node	*right;

}	t_Node;

// parse
int	make_indexed_arr(int **indexed_arr, int argc, char **resource);
int	ft_atoi(const char *str);
int	check_digit(char *check);


#	endif
