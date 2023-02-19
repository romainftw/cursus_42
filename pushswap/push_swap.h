/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:11:52 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/19 14:40:20 by roperrin         ###   ########.fr       */
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
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

void	push_swap(char *tab);
void	s_function(t_list **lst);
void	pa_function(t_list **slack_a, t_list **slack_b);
void	pb_function(t_list **slack_a, t_list **slack_b);
void	r_function(t_list **slack);
void	rra_function(t_list **slack);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	parsing(char **arg, int arc);
void	n_quote(char **str, int count);
void	copy_slack(char	**str, int i);
void	put_index_order(t_list *slack_a);
void	ft_lstclear_pushswap(t_list **lst);
void	choose_strat(int i, t_list *slack_a);
void	third_nb(t_list *slack_a);
void	four_nb(t_list *slack_a, t_list *slack_b);

int		check_neg_index(t_list *slack_a);
int		lowest_in_slack(t_list *slack_a);
int		high_in_slack_whitout_ind(t_list *slack_a);
int		check_order(char **str, int i);
int		check_double(char **str, long int j);
int		check_order_in_lst(t_list *lst);

char	**quote(char *str);

t_list	*lst_new(int data, int index);
t_list	*lst_new_neg(int data);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_prevlast(t_list *lst);

#endif
