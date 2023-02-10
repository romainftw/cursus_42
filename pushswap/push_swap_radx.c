/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:30:58 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/10 11:54:36 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_nb(t_list *slack_a)
{
	t_list	*temp;

	temp = slack_a;
	if (temp->index == 0)
	{
		rr_function(&slack_a);
		s_function(&slack_a);
	}
	else if (temp->index == 1)
	{
		temp = temp->next;
		if (temp->index == 0)
			s_function(&slack_a);
		else
		{
			rr_function(&slack_a);
			rr_function(&slack_a);
		}
	}
	else if (temp->index == 2)
	{
		temp = temp->next;
		if (temp->index == 0)
			r_function(&slack_a);
		else
		{
			rr_function(&slack_a);
			rr_function(&slack_a);
		}
	}
	ft_lstclear_pushswap(&slack_a);
}
