/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:10:51 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/01 19:36:41 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_slack(char	**str, int i)
{
	int		nb_a;
	t_list	*slack_a;
	int		j;

	j = 1;
	slack_a = 0;
	nb_a = 0;
	if (!check_order(str, i))
		ft_exit_fail();
	while (str[i])
	{
		nb_a = ft_atoi(str[i]);
		ft_lstadd_back(&slack_a, lst_new(nb_a));
		i++;
	}
	 while (slack_a)
	 {
	 	printf("data -> %d\n", slack_a->content);
	 	slack_a = slack_a->next;
	 }
}

int	check_order(char **str, int i)
{
	int	j;
	int	k;
	int	nb_a;
	int	nb_b;

	k = 0;
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
