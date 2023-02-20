/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:10:51 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/20 13:27:03 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_slack(char	**str, int i, t_slack ctx)
{
	int		nb_a;
	t_list	*slack_a;
	int		c;

	c = 0;
	slack_a = 0;
	nb_a = 0;
	if (!check_order(str, i))
		ft_exit_fail();
	while (str[i])
	{
		nb_a = ft_atoi(str[i]);
		ft_lstadd_back(&slack_a, lst_new_neg(nb_a));
		i++;
		c++;
	}
	i -= 1;
	put_index_order(slack_a);
	choose_strat(i, &slack_a);
}

int	check_order(char **str, int i)
{
	int	j;
	int	nb_a;
	int	nb_b;

	j = i + 1;
	while (str[j])
	{
		nb_a = ft_atoi(str[i]);
		nb_b = ft_atoi(str[j]);
		if (nb_a > nb_b)
			return (1);
	j++;
	i = j - 1;
	}
	return (0);
}

void	put_index_order(t_list *slack_a)
{
	t_list	*temp;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (check_neg_index(slack_a))
	{
		nb = lowest_in_slack(slack_a);
		temp = slack_a;
		while (temp)
		{
			if (temp->content == nb)
			{
				temp->index = i;
				i++;
			}
		temp = temp->next;
		}	
	}
}

void	choose_strat(int i, t_list **slack_a)
{
	t_list	**slack_b;

	slack_b = NULL;
	if (i == 2)
		s_function(slack_a);
	if (i == 3)
		third_nb(slack_a);
	if (i == 4)
		four_nb(slack_a, slack_b);
	if (i == 5)
		five_nb(slack_a, slack_b);
}
