/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:26:02 by roperrin          #+#    #+#             */
/*   Updated: 2022/12/14 19:42:39 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	temp = lst;
	if (!lst || !f || !del)
		return (NULL);
	//new = ft_lstnew(f(temp->content));
	new = NULL;
	while (temp)
	{
		new = ft_lstnew(f(temp->content));
		temp = temp->next;
		//new->next = temp;
		new = new->next;
	}
	new->next = NULL;
	return (new);
}
