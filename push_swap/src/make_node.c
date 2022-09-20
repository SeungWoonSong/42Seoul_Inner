/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:57:58 by susong            #+#    #+#             */
/*   Updated: 2022/09/20 10:44:56 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

DoubleList	*init_node(void)
{
	DoubleList	*list;

	list = (DoubleList *)malloc(sizeof(DoubleList));
	if (!list)
		return (0);
	list->currentElementCount = 0;
	list->headerNode.left = &list->headerNode;
	list->headerNode.right = &list->headerNode;
	list->headerNode.data = -1;
	list->headerNode.index = -1;
	return (list);
}

int	add_node_back(DoubleList *head, int *index_arr, int data)
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
	prev = head->headerNode.right;
	while (index_arr[index_num] != data)
		index_num++;
	while (temp++ < head->currentElementCount)
		prev = prev->right;
	head->currentElementCount += 1;
	new->index = index_num;
	new->data = data;
	new->left = prev;
	prev->right = new;
	new->right = &head->headerNode;
	head->headerNode.left = new;
	return (1);
}

DoubleList	*make_stack_a(int index, int *indexed_arr, int *arr)
{
	DoubleList	*head;
	int			i;

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
