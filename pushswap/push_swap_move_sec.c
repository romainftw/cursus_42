/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_sec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:52:57 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/21 11:14:28 by roperrin         ###   ########.fr       */
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

int	lowest_in_slack_no_ind(t_list *slack_a)
{
	t_list	*temp;
	int		nb_min;

	nb_min = 2147483647;
	temp = slack_a;
	while (temp)
	{
		if (temp->content < nb_min)
			nb_min = temp->content;
		temp = temp->next;
	}
	return (nb_min);
}