/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:09:14 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/19 15:15:44 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "lib/libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "lib/ft_printf/ft_printf.h"
# include "lib/gnl/get_next_line.h"

int		pars_first(char *map_file);
int		compo_check(char **map);
int		line_check(char **map);
int		line_size_check(char **map);
int		col_size_check(char **map);
int		possible(char **map);
int		x_map(char **map);

char	**copy_map(char *map_file, char **map);
char	**map_size(char *map);

#endif