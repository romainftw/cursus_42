/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:35:39 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/24 19:09:13 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	up_move(int j, int i, t_data *mlx)
{
	if (mlx->map[j - 1][i] && (mlx->map[j - 1][i] == '0' \
	|| mlx->map[j - 1][i] == 'C'))
	{
		mlx->map[j - 1][i] = 'P';
		mlx->map[j][i] = '0';
		map_gen(mlx);
		mlx->count++;
		ft_printf("%d\n", mlx->count);
	}
	else if (mlx->map[j - 1][i] && ((mlx->map[j - 1][i] == 'E' \
	&& exit_ok(mlx))))
		exit (0);
	return (0);
}

int	down_move(int j, int i, t_data *mlx)
{
	if (mlx->map[j + 1][i] && (mlx->map[j + 1][i] == '0' \
	|| mlx->map[j + 1][i] == 'C'))
	{
		mlx->map[j + 1][i] = 'P';
		mlx->map[j][i] = '0';
		map_gen(mlx);
		mlx->count++;
		ft_printf("%d\n", mlx->count);
	}
	else if (mlx->map[j + 1][i] && ((mlx->map[j + 1][i] == 'E' \
	&& exit_ok(mlx))))
		exit (0);
	return (0);
}

int	right_move(int j, int i, t_data *mlx)
{
	if (mlx->map[j][i + 1] && (mlx->map[j][i + 1] == '0' \
	|| mlx->map[j][i + 1] == 'C'))
	{
		mlx->map[j][i + 1] = 'P';
		mlx->map[j][i] = '0';
		map_gen(mlx);
		mlx->count++;
		ft_printf("%d\n", mlx->count);
	}
	else if (mlx->map[j][i + 1] && ((mlx->map[j][i + 1] == 'E' \
		&& exit_ok(mlx))))
		exit (0);
	return (0);
}

int	left_move(int j, int i, t_data *mlx)
{
	if (mlx->map[j][i - 1] && (mlx->map[j][i - 1] == '0' \
	|| mlx->map[j][i - 1] == 'C'))
	{
		mlx->map[j][i - 1] = 'P';
		mlx->map[j][i] = '0';
		map_gen(mlx);
		mlx->count++;
		ft_printf("%d\n", mlx->count);
	}
	else if (mlx->map[j][i - 1] && ((mlx->map[j][i - 1] == 'E' \
	&& exit_ok(mlx))))
		exit (0);
	return (0);
}

int	exit_ok(t_data *mlx)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = -1;
	j = -1;
	while (mlx->map[++j])
	{
		while (mlx->map[j][++i])
		{
			if (mlx->map[j][i] == 'C')
			x = 1;
		}
		i = -1;
	}
	if (x != 0)
		return (0);
	return (1);
}
