/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:57:58 by susong            #+#    #+#             */
/*   Updated: 2022/09/21 14:09:45 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_doublelist	*init_node(void)
{
	t_doublelist	*list;

	list = (t_doublelist *)malloc(sizeof(t_doublelist));
	if (!list)
		return (0);
	list->currentelementcount = 0;
	list->headernode.left = &list->headernode;
	list->headernode.right = &list->headernode;
	list->headernode.data = -1;
	list->headernode.index = -1;
	return (list);
}

int	add_node_back(t_doublelist *head, int *index_arr, int data)
{
	int		index_num;
	int		temp;
	t_node	*new;
	t_node	*prev;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	temp = 1;
	index_num = 0;
	prev = head->headernode.right;
	while (index_arr[index_num] != data)
		index_num++;
	while (temp++ < head->currentelementcount)
		prev = prev->right;
	head->currentelementcount += 1;
	new->index = index_num;
	new->data = data;
	new->left = prev;
	prev->right = new;
	new->right = &head->headernode;
	head->headernode.left = new;
	return (1);
}

t_doublelist	*make_stack_a(int index, int *indexed_arr, int *arr)
{
	t_doublelist	*head;
	int				i;

	i = 0;
	head = init_node();
	while (i < index - 1)
	{
		if (!add_node_back(head, indexed_arr, arr[i]))
			return (0);
		i++;
	}
	return (head);
}
