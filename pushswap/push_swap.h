/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:11:52 by roperrin          #+#    #+#             */
/*   Updated: 2022/12/18 19:34:08 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				element;
	struct s_list	*next;
}	t_list;

void	push_swap(char *tab);
void	s_function(t_list **lst);
void	p_function(t_list **slack_a, t_list **slack_b);
void	r_function(t_list **slack);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

size_t	ft_strlen(const char *s);

void	ft_lstadd_front(t_list **lst, t_list *new);

#endif