/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:22:30 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/02 11:10:13 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*tab_temp;

	i = 0;
	if (argc <= 1)
		return (0);
	while (*argv[i - 1])
		i ++;
	tab_temp = malloc(sizeof(int) * i);
	i = 0;
	while (argv[i])
	{
		tab_temp[i] = *argv[i +1];
		i ++;
	}
	if (!pars_sec(tab_temp))
	{
		free(tab_temp);
		return (0);
	}
	return (0);
}
