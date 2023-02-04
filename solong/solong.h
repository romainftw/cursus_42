/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:09:14 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/31 14:16:59 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "lib/ft_printf/ft_printf.h"
# include "lib/gnl/get_next_line.h"
# include "lib/libft/libft.h"

typedef struct s_data {
	void	*img_wall;
	void	*img_player;
	void	*img_exit;
	void	*img_collec;
	void	*img_floor;
	char	**map;
	void	*mlx;
	int		line;
	void	*mlx_win;
	int		count;
	int		i;
	int		j;
}				t_data;

int		pars_first(char *map_file);
int		compo_check(char **map);
int		line_check(char **map);
int		line_size_check(char **map);
int		col_size_check(char **map);
int		possible(char **map);
int		x_map(char **map);
int		change_zero_to_x(char **map);
int		print_map(char **map);
int		possible_exit(char **map, char h);
int		collect_check(char **map);
int		check_extension(char **arg);
int		move_player(int keycode, t_data *mlx);
int		notify(int keycode, void *param);
int		up_move(int j, int i, t_data *mlx);
int		down_move(int j, int i, t_data *mlx);
int		right_move(int j, int i, t_data *mlx);
int		left_move(int j, int i, t_data *mlx);
int		player_pos(t_data *mlx, int move);
void	choose_move(t_data *mlx, int j, int i, int move);
void	setup_mlx(char **map);
void	map_gen(t_data *mlx);
int		exit_ok(t_data *mlx);
int		check_acces_col(char **map);

int		print_map(char **map);

char	**copy_map(char *map_file, char **map);
char	**map_size(char *map);

#endif