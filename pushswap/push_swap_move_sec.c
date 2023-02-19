/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_sec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:52:57 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/19 12:53:32 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_function(t_list **slack_a, t_list **slack_b)
{
	t_list	*temp_a;

	if (!slack_a || !slack_b)
		return ;
	temp_a = *slack_a;
	*slack_a = (*slack_a)->next;
	temp_a->next = *slack_b;
	*slack_b = temp_a;
	ft_printf("pb\n");
}
