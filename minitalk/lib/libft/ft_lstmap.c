/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:26:02 by roperrin          #+#    #+#             */
/*   Updated: 2022/12/15 16:45:36 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*new_one;

	temp = lst;
	new = NULL;
	new_one = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (temp)
	{
		new = ft_lstnew(f(temp->content));
		if (!new)
		{
			ft_lstclear(&new_one, del);
			return (NULL);
		}
		ft_lstadd_back(&new_one, new);
		temp = temp->next;
	}
	return (new_one);
}
