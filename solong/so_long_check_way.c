/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:04:26 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/24 18:35:10 by roperrin         ###   ########.fr       */
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
	if (change_zero_to_x(map))
	{
		if (possible_exit(map, 'E') && (!check_acces_col(map)))
			return (1);
	}
	return (0);
}

int	possible_j(char **map, int j, int i)
{
	if (map[j][i] == 'x')
	{
		if (map[j + 1][i] == '0'
			|| map[j + 1][i] == 'C')
		{
			map[j + 1][i] = 'x';
			return (1);
		}
		if ((map[j - 1][i] == '0'
			|| map[j - 1][i] == 'C'))
		{
			map[j - 1][i] = 'x';
			return (1);
		}
	}
	return (0);
}

int	possible_i(char **map, int j, int i)
{
	if (map[j][i] == 'x')
	{
		if (map[j][i + 1] == '0'
			|| map[j][i + 1] == 'C')
		{
			map[j][i + 1] = 'x';
			return (1);
		}
		if (map[j][i - 1] == '0'
			|| map[j][i - 1] == 'C')
		{
			map[j][i - 1] = 'x';
			return (1);
		}
	}
	return (0);
}

int	change_zero_to_x(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (possible_i(map, j, i) || possible_j(map, j, i))
			{
				i = 0;
				j = 0;
			}
			i++;
		}
		if (possible_i(map, j, i) || possible_j(map, j, i))
			j = 0;
		i = 0;
		j++;
	}
	return (1);
}

int	possible_exit(char **map, char h)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (map[j][i] == h)
			{
				if ((map[j][i + 1] && map[j][i + 1] == 'x')
					|| (map[j][i - 1] && map[j][i - 1] == 'x')
						|| (map[j + 1][i] && map[j + 1][i] == 'x')
							|| (map[j - 1][i] && map[j - 1][i] == 'x'))
					x = 1;
			}
		}
		i = 0;
	}
	if (x == 1)
		return (1);
	return (0);
}
