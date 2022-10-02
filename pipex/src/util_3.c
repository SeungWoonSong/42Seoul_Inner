/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:33:45 by susong            #+#    #+#             */
/*   Updated: 2022/10/02 15:34:44 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void free_array(char **array)
{
	int index;

	index = 0;
	while(array[index] != NULL)
	{
		free(array[index]);
		index++;
	}
	free(array);
	return ;
}
