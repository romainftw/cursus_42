/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:28:33 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/04 18:21:12 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	pars_first(char *map_file)
{
	char	**map;

	map = NULL;
	map = copy_map(map_file, map);
	if (!compo_check(map) || !line_check(map))
		return (0);
	return (1);
}
