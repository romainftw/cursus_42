/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:16:37 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/21 11:15:45 by roperrin         ###   ########.fr       */
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
	// t_list	*temp_a;

	low = lowest_in_slack_no_ind((*ctx)->a);
	while ((*ctx)->a->content != low)
		ra_function(ctx);
	pb_function(ctx);
	if (check_order_in_lst((*ctx)->a))
		third_nb(ctx);
	pa_function(ctx);
	// temp_a = (*ctx)->a;
	// printf("------------A4---------------\n");
	// while (temp_a)
	// {
	// 	printf("------[%d]\n", temp_a->index);
	// 	printf("%d\n", temp_a->content);
	// 	temp_a = temp_a->next;
	// }
	// printf("------------A4---------------\n");
}

void	five_nb(t_stack **ctx)
{
	// t_list	*temp_a;
	int		low;
	int		i;

	i = 0;
	low = lowest_in_slack_no_ind((*ctx)->a);
	while ((*ctx)->a->content != low)
		ra_function(ctx);
	pb_function(ctx);
	four_nb(ctx);
	pa_function(ctx);
	// temp_a = (*ctx)->a;
	// printf("------------A5---------------\n");
	// while (temp_a)
	// {
	// 	printf("------[%d]\n", temp_a->index);
	// 	printf("--[%d]\n", temp_a->place);
	// 	printf("%d\n", temp_a->content);
	// 	temp_a = temp_a->next;
	// }
	// printf("------------A5---------------\n");
}
