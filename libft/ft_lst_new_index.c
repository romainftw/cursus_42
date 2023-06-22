/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:59:05 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/04 19:59:36 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*lst_new_index(int data, int i)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = data;
	new->index = i;
	new->next = NULL;
	return (new);
}