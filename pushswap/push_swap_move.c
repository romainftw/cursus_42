/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:13:24 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/20 16:47:28 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_function(t_stack **ctx)
{
	t_list	*bufn;

	if ((*ctx)->a == NULL)
		return ;
	bufn = (*ctx)->a->next;
	(*ctx)->a->next = (*ctx)->a->next->next;
	bufn->next = (*ctx)->a;
	(*ctx)->a = bufn;
	ft_printf("sa\n");
}

void	pa_function(t_stack **ctx)
{
	t_list	*temp_b;

	if ((*ctx)->b == NULL)
		return ;
	temp_b = (*ctx)->b;
	(*ctx)->b = (*ctx)->b->next;
	temp_b->next = (*ctx)->a;
	(*ctx)->a = temp_b;
	ft_printf("pa\n");
}

void	ra_function(t_stack **ctx)
{
	t_list	*last;
	t_list	*temp;

	if ((*ctx)->a == NULL)
		return ;
	last = ft_prevlast((*ctx)->a);
	last->next = (*ctx)->a;
	temp = (*ctx)->a->next;
	last->next->next = NULL;
	(*ctx)->a = temp;
	ft_printf("ra\n");
}

void	rra_function(t_stack **ctx)
{
	t_list				*temp_a;
	t_list				*last;

	if ((*ctx)->a == NULL)
		return ;
	temp_a = (*ctx)->a;
	last = (*ctx)->a;
	last = ft_prevlast(last);
	last->next = temp_a;
	temp_a->next->next = NULL;
	(*ctx)->a = last;
	ft_printf("rra\n");
}

t_list	*ft_prevlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
	{
		lst = lst->next;
	}
	if (lst->next)
		lst = lst->next;
	return (lst);
}
