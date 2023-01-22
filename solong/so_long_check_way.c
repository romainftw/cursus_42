/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:04:26 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/22 13:53:29 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	x_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				map[j][i] = 'x';
				break ;
			}
			i++;
		}
		i = 0;
		j++;
	}
		possible(map);
		possible(map);
		possible(map);
		possible(map);
		possible(map);
	return (1);
}

int	possible(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		i++;
		if (map[j][i + 1] == '0')
			return (1);
		if (map[j][i - 1] == '0')
			return (1);
		if (map[j + 1][i] == '0')
			return (1);
		if (map[j - 1][i] == '0')
			return (1);
		j++;
		i = 0;
	}
	return (0);
}
