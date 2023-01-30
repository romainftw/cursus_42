/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:13:24 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/30 15:57:48 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_function(t_list **lst)
{
	t_list	*temp;
	t_list	*temp_s;
	int		cache;
	int		cache_s;

	temp = *lst;
	temp_s = *lst;
	if (!lst)
		return ;
	temp = temp->next;
	cache = temp->element;
	cache_s = temp_s->element;
	temp->element = cache_s;
	temp_s->element = cache;
}

void	p_function(t_list **slack_a, t_list **slack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		cache;

	if (!slack_a || !slack_b)
		return ;
	temp_a = *slack_a;
	temp_b = *slack_b;
	cache = temp_b->element;
	ft_lstadd_front(slack_a, lst_new(cache));
	*slack_b = temp_b->next;
}

void	r_function(t_list **slack)
{
	t_list	*temp;
	int		cache;

	if (!slack)
		return ;
	temp = *slack;
	cache = temp->element;
	ft_lstadd_back(&temp, lst_new(cache));
	*slack = temp->next;
}

void	rr_function(t_list **slack)
{
	t_list				*temp;
	t_list				*temp_a;

	if (!slack)
		return ;
	temp_a = *slack;
	temp_a = ft_prevlast(temp_a);
	temp = temp_a->next;
	temp_a->next->next = *slack;
	temp_a->next = NULL;
	*slack = temp;
	free(temp_a);
}
