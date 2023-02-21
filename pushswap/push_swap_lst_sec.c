/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_sec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:56:19 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/21 20:15:37 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	high_in_slack_whitout_ind(t_list *slack_a)
{
	t_list	*temp;
	int		nb_min;

	nb_min = -2147483647;
	temp = slack_a;
	while (temp)
	{
		if (temp->content > nb_min)
			nb_min = temp->content;
		temp = temp->next;
	}
	return (nb_min);
}

t_list	*lst_new_neg(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = data;
	new->index = -1;
	new->next = NULL;
	return (new);
}

int	check_order_in_lst(t_list *lst)
{
	t_list	*nb_a;
	t_list	*nb_b;
	int		val_a;
	int		val_b;

	nb_a = lst;
	nb_b = lst->next;
	while (nb_b)
	{
		val_a = nb_a->index;
		val_b = nb_b->index;
		if (val_a > val_b)
			return (1);
		nb_b = nb_b->next;
		nb_a = nb_a->next;
	}
	return (0);
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

void	ft_lstsize(t_stack **ctx)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = (*ctx)->a;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	(*ctx)->a->len = i;
}
