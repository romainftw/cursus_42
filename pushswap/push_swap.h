/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:11:52 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/21 20:08:59 by roperrin         ###   ########.fr       */
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
	int				place;
	int				len;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		quote;
}	t_stack;

void	sa_function(t_stack **lst);
void	pa_function(t_stack **ctx);
void	pb_function(t_stack **ctx);
void	ra_function(t_stack **ctx);
void	rra_function(t_stack **ctx);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	parsing(char **arg, int arc, t_stack *ctx);
void	n_quote(char **str, int count);
void	copy_slack(char	**str, t_stack *ctx);
void	put_index_order(t_list **ctx);

void	ft_lstsize(t_stack **ctx);
void	choose_strat(int i, t_stack *slack_a);
void	third_nb(t_stack **ctx);
void	four_nb(t_stack **ctx);
void	five_nb(t_stack **ctx);
void	rad_x(t_stack **ctx);

int		check_neg_index(t_list **slack_a);
int		lowest_in_slack(t_list *slack_a);
int		lowest_in_slack_no_ind(t_list *slack_a);
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
