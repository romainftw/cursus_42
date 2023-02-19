/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:16:37 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/19 18:00:12 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_nb(t_list *slack_a)
{
	int		val_one;
	int		val_two;
	int		val_three;
t_list	*temp_a;
	val_one = slack_a->index;
	val_two = slack_a->next->index;
	val_three = slack_a->next->next->index;
	if (val_one < val_two && val_two > val_three \
	&& val_one < val_three)
	{
		rra_function(&slack_a);
		s_function(&slack_a);
	}
	else if (val_one > val_two && val_two < val_three \
	&& val_one < val_three)
		s_function(&slack_a);
	else if (val_one < val_two && val_two > val_three)
		rra_function(&slack_a);
	else if (val_one > val_two && val_two < val_three)
		r_function(&slack_a);
	else if (val_one > val_two && val_two > val_three)
	{
		r_function(&slack_a);
		s_function(&slack_a);
	}
		temp_a = slack_a;
	printf("------------A---------------\n");
	while (temp_a)
	{
		printf("------[%d]\n", temp_a->index);
		printf("%d\n", temp_a->content);
		temp_a = temp_a->next;
	}
	printf("------------A---------------\n");
}

void	four_nb(t_list *slack_a, t_list *slack_b)
{
	int		max;
	t_list	*temp;
	t_list	*temp_a;

	temp = slack_a;
	max = high_in_slack_whitout_ind(slack_a);
	while (slack_a->content != max)
		r_function(&slack_a);
	pb_function(&slack_a, &slack_b);
	if (check_order_in_lst(slack_a))
	{
		third_nb(slack_a);
		printf("------------3---------------\n");
	}
	pa_function(&slack_a, &slack_b);
	r_function(&slack_a);
	temp_a = slack_a;
	printf("------------A---------------\n");
	while (temp_a)
	{
		printf("------[%d]\n", temp_a->index);
		printf("%d\n", temp_a->content);
		temp_a = temp_a->next;
	}
	printf("------------A---------------\n");
}
