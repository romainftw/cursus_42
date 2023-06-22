/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:54:03 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/31 18:05:47 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_addback(t_list **lst, t_list *new)
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
