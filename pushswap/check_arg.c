/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:30:09 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/31 12:48:27 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pars_one(char *tab)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i] < '0' || tab [i] > '9')
			return (0);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		while (tab[j])
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	pars_sec(char *tab)
{
	int	i;

	i = 0;
	printf("-------------------------pars1-------------");
	if (!pars_one(tab))
		return (0);
	while (tab[i])
	{
		if (!(tab[i] < tab[i + 1]))
			return (1);
		i++;
	}
	return (0);
}
