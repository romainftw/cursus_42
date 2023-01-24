/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_graphic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:01:08 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/24 16:26:56 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	get_n_line(t_data *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[i])
		i++;
	mlx->line = i;
}

void	setup_mlx(char **map)
{
	t_data	mlx;
	int		i;

	i = 16;
	mlx.mlx = mlx_init();
	mlx.map = map;
	get_n_line(&mlx);
	printf("%d", mlx.line);
	mlx.img_player = mlx_xpm_file_to_image(mlx.mlx, "img/player.xpm", &i, &i);
	mlx.img_wall = mlx_xpm_file_to_image(mlx.mlx, "img/wall.xpm", &i, &i);
	mlx.img_exit = mlx_xpm_file_to_image(mlx.mlx, "img/exit.xpm", &i, &i);
	mlx.img_collec = mlx_xpm_file_to_image(mlx.mlx, "img/collect.xpm", &i, &i);
	mlx.img_floor = mlx_xpm_file_to_image(mlx.mlx, "img/floor.xpm", &i, &i);
	mlx.mlx_win = mlx_new_window(mlx.mlx, \
	ft_strlen(map[0]) * 16, mlx.line * 16, "roperrin_solong");
	if (!mlx.img_player || !mlx.img_wall || !mlx.img_exit || !mlx.img_collec \
		|| !mlx.img_floor)
		exit(0);
	map_gen(&mlx);
	mlx_hook(mlx.mlx_win, 2, (1L << 0), move_player, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, notify, NULL);
	mlx_loop(mlx.mlx);
}

void	map_gen(t_data *mlx)
{
	mlx->i = -1;
	mlx->j = -1;
	while (mlx->map[++mlx->j])
	{
		while (mlx->map[mlx->j][++mlx->i])
		{
			if (mlx->map[mlx->j][mlx->i] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_wall, \
				mlx->i * 16, mlx->j * 16);
			if (mlx->map[mlx->j][mlx->i] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_floor, \
				mlx->i * 16, mlx->j * 16);
			if (mlx->map[mlx->j][mlx->i] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
				mlx->img_player, mlx->i * 16, mlx->j * 16);
			if (mlx->map[mlx->j][mlx->i] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
				mlx->img_collec, mlx->i * 16, mlx->j * 16);
			if (mlx->map[mlx->j][mlx->i] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img_exit, \
				mlx->i * 16, mlx->j * 16);
		}
		mlx->i = -1;
	}
	print_map(mlx->map);
}
