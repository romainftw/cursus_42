/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_sec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:52:57 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/13 16:00:45 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_function(t_list **slack_b, t_list **slack_a)
{
	t_list	*temp_b;
	t_list	*temp_next;
	int		cache;

	if (!slack_a || !slack_b)
		return ;
	temp_b = *slack_a;
	cache = temp_b->content;
	ft_lstadd_front(slack_b, lst_new(cache));
	temp_next = temp_b->next;
	free(temp_b);
	temp_b = temp_next;
	ft_printf("pb\n");
}
