/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_sec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:52:57 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/20 16:02:57 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_function(t_stack **ctx)
{
	t_list	*temp_a;

	temp_a = (*ctx)->a;
	(*ctx)->a = (*ctx)->a->next;
	temp_a->next = (*ctx)->b;
	(*ctx)->b = temp_a;
	ft_printf("pb\n");
}
