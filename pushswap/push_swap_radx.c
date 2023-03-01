/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:16:37 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/25 16:59:40 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_nb(t_stack **ctx)
{
	int		val_one;
	int		val_two;
	int		val_three;

	val_one = (*ctx)->a->index;
	val_two = (*ctx)->a->next->index;
	val_three = (*ctx)->a->next->next->index;
	if (val_one < val_two && val_two > val_three \
	&& val_one < val_three)
	{
		rra_function(ctx);
		sa_function(ctx);
	}
	else if (val_one > val_two && val_two < val_three \
	&& val_one < val_three)
		sa_function(ctx);
	else if (val_one < val_two && val_two > val_three)
		rra_function(ctx);
	else if (val_one > val_two && val_two < val_three)
		ra_function(ctx);
	else if (val_one > val_two && val_two > val_three)
	{
		ra_function(ctx);
		sa_function(ctx);
	}
}

void	four_nb(t_stack **ctx)
{
	int		low;

	low = lowest_in_slack_no_ind((*ctx)->a);
	while ((*ctx)->a->content != low)
		ra_function(ctx);
	pb_function(ctx);
	if (check_order_in_lst((*ctx)->a))
		third_nb(ctx);
	pa_function(ctx);
}

void	five_nb(t_stack **ctx)
{
	int		low;
	int		i;

	i = 0;
	if (((*ctx)->a->index == 2 && (*ctx)->a->next->index == 4)
		&& (((*ctx)->a->next->next->index == 3)
			&& (*ctx)->a->next->next->next->index == 1))
		special_ka(ctx);
	if (((*ctx)->a->index == 4 && (*ctx)->a->next->index == 3)
		&& (((*ctx)->a->next->next->index == 2)
			&& (*ctx)->a->next->next->next->index == 1))
		special_kb(ctx);
	if (!check_order_in_lst((*ctx)->a))
		ft_exit_succes();
	low = lowest_in_slack_no_ind((*ctx)->a);
	while ((*ctx)->a->content != low)
		ra_function(ctx);
	if (!check_order_in_lst((*ctx)->a))
		ft_exit_succes();
	pb_function(ctx);
	four_nb(ctx);
	pa_function(ctx);
}

void	rad_x(t_stack **ctx)
{
	int	j;
	int	len;
	int	i;

	i = 0;
	j = 0;
	ft_lstsize(ctx);
	len = (*ctx)->a->len;
	while (check_order_in_lst((*ctx)->a))
	{
		while (j < len)
		{
			if (!(((*ctx)->a->place >> i) & 1))
				pb_function(ctx);
			else
				ra_function(ctx);
			j++;
		}
		i++;
		j = 0;
		while ((*ctx)->b)
			pa_function(ctx);
	}
}
