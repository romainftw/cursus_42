/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:09:14 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/04 18:09:11 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

int		pars_first(char *map_file);
int		compo_check(char **map);
int		line_check(char **map);

char	**copy_map(char *map_file, char **map);
char	**map_size(char *map);

#endif