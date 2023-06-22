/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:16:33 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/24 19:10:11 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	notify(int keycode, void *param)
{
	(void) param;
	(void) keycode;
	exit(0);
}

int	move_player(int keycode, t_data *mlx)
{
	(void) mlx;
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		player_pos(mlx, 1);
	else if (keycode == 125)
		player_pos(mlx, 2);
	else if (keycode == 124)
		player_pos(mlx, 3);
	else if (keycode == 123)
		player_pos(mlx, 4);
	return (0);
}

int	player_pos(t_data *mlx, int move)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (mlx->map[++j])
	{
		while (mlx->map[j][++i])
		{
			if (mlx->map[j][i] == 'P')
			{
				choose_move(mlx, j, i, move);
				return (0);
			}
		}
		i = -1;
	}
	return (0);
}

void	choose_move(t_data *mlx, int j, int i, int move)
{
	if (move == 1)
		up_move(j, i, mlx);
	else if (move == 2)
		down_move(j, i, mlx);
	else if (move == 3)
		right_move(j, i, mlx);
	else if (move == 4)
		left_move(j, i, mlx);
}
