/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:13:24 by roperrin          #+#    #+#             */
/*   Updated: 2022/12/17 23:46:40 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_function(t_list **lst)
{
	t_list	*temp;
	t_list	*temp_s;
	int		cache;
	int		cache_s;

	temp = *lst;
	temp_s = *lst;
	if (!lst)
		return ;
	temp = temp->next;
	cache = temp->element;
	cache_s = temp_s->element;
	temp->element = cache_s;
	temp_s->element = cache;
}


