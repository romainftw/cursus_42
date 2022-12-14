/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:47:57 by roperrin          #+#    #+#             */
/*   Updated: 2022/12/14 17:24:14 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*temp_next;

	temp = *lst;
	temp_next = *lst;
	if (!lst || !del)
		return ;
	while (temp)
	{
		temp_next = temp_next->next;
		ft_lstdelone(temp, del);
		temp = temp_next;
	}
	*lst = NULL;
}
