/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_sec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:52:57 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/25 17:01:09 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_function(t_stack **ctx)
{
	t_list	*temp_a;

	if ((*ctx)->a == NULL)
		return ;
	temp_a = (*ctx)->a;
	(*ctx)->a = (*ctx)->a->next;
	temp_a->next = (*ctx)->b;
	(*ctx)->b = temp_a;
	ft_printf("pb\n");
}

void	special_ka(t_stack **ctx)
{
	ra_function(ctx);
	ra_function(ctx);
	ra_function(ctx);
	sa_function(ctx);
	pb_function(ctx);
	pb_function(ctx);
	rra_function(ctx);
	sa_function(ctx);
	pa_function(ctx);
	pa_function(ctx);
}

void	special_kb(t_stack **ctx)
{
	ra_function(ctx);
	ra_function(ctx);
	ra_function(ctx);
	sa_function(ctx);
}
