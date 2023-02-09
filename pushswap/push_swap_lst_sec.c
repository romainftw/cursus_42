/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_sec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:56:19 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/09 14:53:23 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_pushswap(t_list **lst)
{
	t_list	*temp;
	t_list	*temp_next;

	temp = *lst;
	temp_next = *lst;
	while (temp)
	{
		temp_next = temp_next->next;
		free(temp);
		temp = temp_next;
	}
	*lst = NULL;
	free(temp);
}
