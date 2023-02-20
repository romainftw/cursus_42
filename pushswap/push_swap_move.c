/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:13:24 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/20 14:53:10 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_function(t_list **lst)
{
	t_list	*bufn;

	bufn = (*lst)->next;
	if (!lst)
		return ;
	(*lst)->next = (*lst)->next->next;
	bufn->next = *lst;
	*lst = bufn;
	
	while (lst)
	{
		printf("%d----------\n", (*lst)->content);
		printf("[%d]----------\n", (*lst)->index);
		lst = &(*lst)->next;
	}
	
	ft_printf("sa\n");
}

void	pa_function(t_list **slack_a, t_list **slack_b) // (t_stack *stack)
{
	t_list	*temp_b;

	if (!slack_a || !slack_b)
		return ;
	temp_b = *slack_b;
	*slack_b = (*slack_b)->next;
	temp_b->next = *slack_a;
	*slack_a = temp_b;
	ft_printf("pa\n");
}

void	r_function(t_list **slack)
{
	t_list	*last;
	t_list	*temp;

	if (!slack)
		return ;
	last = ft_prevlast(*slack);
	last->next = *slack;
	temp = (*slack)->next;
	last->next->next = NULL;
	*slack = temp;
	ft_printf("ra\n");
}

void	rra_function(t_list **slack)
{
	t_list				*temp_a;
	t_list				*last;

	if (!slack)
		return ;
	temp_a = *slack;
	last = *slack;
	last = ft_prevlast(last);
	last->next = temp_a;
	temp_a->next->next = NULL;
	*slack = last;
	ft_printf("rra\n");
}

t_list	*ft_prevlast(t_list *slack)
{
	if (!slack)
		return (NULL);
	while (slack->next->next)
	{
		slack = slack->next;
	}
	if (slack->next)
		slack = slack->next;
	return (slack);
}
