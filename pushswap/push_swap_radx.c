/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:30:58 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/13 15:56:14 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_nb(t_list *slack_a)
{
	t_list	*temp;

	temp = slack_a;
	if (temp->index == 0)
	{
		rra_function(&slack_a);
		s_function(&slack_a);
	}
	else if (temp->index == 1)
	{
		temp = temp->next;
		if (temp->index == 0)
			s_function(&slack_a);
		else
			rra_function(&slack_a);
	}
	else if (temp->index == 2)
	{
		temp = temp->next;
		if (temp->index == 0)
			r_function(&slack_a);
		else if (temp->index == 1)
		{
			s_function(&slack_a);
			r_function(&slack_a);
			r_function(&slack_a);
		}
	}
	//  t_list *temp_a;

	//  temp_a = slack_a;
	//  while (temp_a)
	//  {
	//  	printf("------[%d]\n", temp_a->index);
	//  	printf("%d\n", temp_a->content);
	//  	temp_a = temp_a->next;
	//  }
	ft_lstclear_pushswap(&slack_a);
}

void	four_nb(t_list *slack_a, t_list *slack_b)
{
	t_list	*temp;

	temp = slack_a;
	if (temp->index == 3)
	{
		pb_function(&slack_b, &temp);
		t_list *temp_a;

	 temp_a = slack_a;
	 while (temp_a)
	 {
	 	printf("------[%d]\n", temp_a->index);
	 	printf("%d\n", temp_a->content);
	 	temp_a = temp_a->next;
	 }
		third_nb(slack_a);
		pa_function(&slack_a, &slack_b);
		s_function(&slack_a);
	}
}
