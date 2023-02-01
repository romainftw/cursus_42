/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:30:09 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/01 12:49:35 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n_quote(char **str, int count)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < count)
	{
		if (str[i][j] == '-')
			j++;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				ft_exit_fail();
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = -1;
}

// int	check_double(char *str)
// {
// 	int	nb_a;
// 	int	nb_b;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 1;
// 	nb_a = 0;
// 	nb_b = 0;
// 	while (str[i])
// 	{
// 		nb_a = ft_atoi(str[i]);
// 		while (str[j])
// 		{
// 			nb_b = ft_atoi(str[j]);
// 			if (nb_a == nb_b)
// 				return (0);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	return (1);
// }
