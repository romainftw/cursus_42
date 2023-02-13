/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_sec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:52:57 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/13 11:57:07 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_function(t_list **slack_b, t_list **slack_a)
{
	t_list	*temp_b;
	int		cache;

	if (!slack_a || !slack_b)
		return ;
	temp_b = *slack_b;
	cache = temp_b->content;
	ft_lstadd_front(slack_a, lst_new(cache));
	*slack_b = temp_b->next;
	ft_printf("pb\n");
}
