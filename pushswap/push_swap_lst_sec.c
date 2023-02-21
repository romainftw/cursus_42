/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_sec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:56:19 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/21 11:14:16 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_pushswap(t_list **lst)
{
	t_list	*temp;
	t_list	*temp_next;

	temp = *lst;
	temp_next = *lst;
	while (temp)
	{
		temp_next = temp_next->next;
		free(temp);
		temp = temp_next;
	}
	*lst = NULL;
	free(temp);
}

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

void	lst_place(t_list **ctx)
{
	t_list	*temp_a;
	int		i;

	i = 0;
	temp_a = *ctx;
	while (temp_a)
	{
		temp_a->place = i;
		temp_a = temp_a->next;
		i++;
	}
}
