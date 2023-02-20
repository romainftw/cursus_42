/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:53:50 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/20 14:50:22 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int data, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = data;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = 0;
	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp)
		{
			if (!tmp->next)
			{
				tmp->next = new;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(*lst))
		*lst = new;
	else if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	lowest_in_slack(t_list **slack_a)
{
	t_list	*temp;
	int		nb_min;

	nb_min = 2147483647;
	temp = *slack_a;
	while (temp)
	{
		if (temp->content < nb_min && temp->index == -1)
			nb_min = temp->content;
		temp = temp->next;
	}
	return (nb_min);
}

int	check_neg_index(t_list **slack_a)
{
	t_list	*temp;

	temp = *slack_a;
	while (temp)
	{
		if (temp->index == -1)
			return (1);
		temp = temp->next;
	}
	return (0);
}
