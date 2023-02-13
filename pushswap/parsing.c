/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:30:09 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/09 14:13:36 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(char **arg, int arc)
{
	char	**temp;

	if (arc == 2)
	{
		temp = quote(arg[1]);
		copy_slack(temp, 0);
		free_double_d(temp);
	}
	else
	{
		n_quote(arg, arc);
		copy_slack(arg, 1);
	}
}

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
			if ((!ft_isdigit(str[i][j])) || (!check_double(str, 1)))
			{
				ft_exit_fail();
				free (str);
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = -1;
}

char	**quote(char *str)
{
	int		i;
	int		j;
	char	**temp;

	j = 0;
	i = -1;
	temp = ft_split(str, ' ');
	while (temp[++i])
	{
		if (temp[i][j] == '-')
			j++;
		while (temp[i][j])
		{
			if ((!ft_isdigit(temp[i][j])) || (!check_double(temp, 0)))
			{
				free_double_d(temp);
				ft_exit_fail();
			}
			j++;
		}
		j = 0;
	}
	return (temp);
}

int	check_double(char **str, long int j)
{
	int			nb_a;
	int			nb_b;
	long int	i;

	i = 2;
	nb_a = 0;
	nb_b = 0;
	while (str[j])
	{
		i = j + 1;
		nb_a = ft_atoi(str[j]);
		while (str[i])
		{
			nb_b = ft_atoi(str[i]);
			if (nb_a == nb_b)
			{
				ft_exit_fail();
				free (str);
			}
			i++;
		}
		j++;
	}
	return (1);
}