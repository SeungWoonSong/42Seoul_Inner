/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:16:23 by susong            #+#    #+#             */
/*   Updated: 2022/08/12 17:07:57 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst)
		return ;
	while ((*lst) != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp, del);
	}
	*lst = 0;
	return ;
}
