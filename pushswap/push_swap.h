/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:11:52 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/03 17:33:31 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

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
char	*ft_strjoin(char *s1, char *s2);

int		pars_one(char *tab);
int		pars_sec(char *tab);
int		ft_atoi(const char *str);

size_t	ft_strlen(const char *s);

t_list	*lst_new(int data);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_prevlast(t_list *lst);

#endif
