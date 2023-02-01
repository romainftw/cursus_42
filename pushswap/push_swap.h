/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:11:52 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/01 12:48:32 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include "lib/ft_printf/ft_printf.h"
# include "lib/gnl/get_next_line.h"
# include "lib/libft/libft.h"

typedef struct s_list
{
	int				element;
	struct s_list	*next;
}	t_list;

void	push_swap(char *tab);
void	s_function(t_list **lst);
void	p_function(t_list **slack_a, t_list **slack_b);
void	r_function(t_list **slack);
void	rr_function(t_list **slack);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	n_quote(char **str, int count);
int		check_double(char *str);

t_list	*lst_new(int data);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_prevlast(t_list *lst);

#endif
