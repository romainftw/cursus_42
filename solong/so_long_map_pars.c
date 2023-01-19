/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_pars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:21:20 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/19 12:56:22 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	line_check(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[0][++i])
	{
		if (map[0][i] != '1')
			return (0);
	}
	while (map[++j])
	{
		if (map[j][i - 1] != '1' || map[j][0] != '1')
			return (0);
	}
	i = 0;
	j--;
	while (map[j][++i])
	{
		if (map[j][i] != '1' )
			return (0);
	}
	return (1);
}

int	line_size_check(char **map)
{
	int		j;
	size_t	k;
	int		x;

	x = 0;
	j = 0;
	k = ft_strlen(map[j]);
	j++;
	while (map[j])
	{
		if (k != ft_strlen(map[j]))
			return (0);
		j++;
	}
	return (1);
}

int	col_size_check(char **map)
{
	int		j;
	int		i;
	int		x;

	x = 0;
	i = 0;
	j = 0;
	while (map[j][i])
		i++;
	while (map[j])
	{	
		while (map[j][x])
		{
			x++;
		}
		if (x != i)
			return (0);
		x = 0;
		j++;
	}
	return (1);
}
