/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:28:33 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/19 13:06:05 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	pars_first(char *map_file)
{
	char	**map;

	map = NULL;
	map = copy_map(map_file, map);
	if (!compo_check(map) || !line_check(map))
	{
		printf("compo %d\n", compo_check(map));
		printf("line  %d\n", line_check(map));
		return (0);
	}
	if (!line_size_check(map) || !col_size_check(map))
		return (0);
	if (!possible(map))
		return (0);
	return (1);
}
