/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:22:30 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/25 17:46:21 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*tab_temp;

	tab_temp = NULL;
	i = 0;
	if (argc <= 1)
		return (0);
	i = 0;
	printf("----------------------------main---------------------\n");
	tab_temp = ft_strjoin(tab_temp, argv[1]);
	printf("----------------------------main---------------------\n");
	if (!pars_sec(tab_temp))
	{
		free(tab_temp);
		return (0);
	}
	printf("----------------------------main---------------------\n");
	return (0);
}
