/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_sec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:56:19 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/13 12:06:06 by roperrin         ###   ########.fr       */
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

	nb_min = - 2147483647;
	temp = slack_a;
	while (temp)
	{
		if (temp->content > nb_min)
			nb_min = temp->content;
		temp = temp->next;
	}
	return (nb_min);
}