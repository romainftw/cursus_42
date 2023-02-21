/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:10:51 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/21 11:19:31 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_slack(char	**str, t_stack *ctx)
{
	int		nb_a;
	int		c;
	int		i;

	c = 0;
	nb_a = 0;
	i = ctx->quote;
	if (!check_order(str, i))
		ft_exit_succes();
	while (str[i])
	{
		nb_a = ft_atoi(str[i]);
		if (nb_a > 2147483647 || nb_a < (-2147483648))
			ft_exit_fail();
		ft_lstadd_back(&ctx->a, lst_new_neg((int)nb_a));
		i++;
		c++;
	}
	put_index_order(&ctx->a);
	lst_place(&ctx->a);
	choose_strat(i, ctx);
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

void	put_index_order(t_list **ctx)
{
	t_list	*temp;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (check_neg_index(ctx))
	{
		nb = lowest_in_slack((*ctx));
		temp = *ctx;
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

void	choose_strat(int i, t_stack *ctx)
{
	if (ctx->quote == 1)
		i -= 1;
	if (i == 2)
		sa_function(&ctx);
	if (i == 3)
		third_nb(&ctx);
	if (i == 4)
		four_nb(&ctx);
	if (i == 5)
		five_nb(&ctx);
}
