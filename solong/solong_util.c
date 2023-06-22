/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:38:05 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/24 18:30:30 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		printf("%s\n", map[j]);
		while (map[j][i])
		{
			i++;
		}
		i = 0;
		j++;
	}
	printf("\n");
	return (1);
}

int	check_acces_col(char **map)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'C')
			{
				x++;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (x);
}
