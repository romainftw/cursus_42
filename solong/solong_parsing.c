/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:28:33 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/23 12:07:52 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	pars_first(char *map_file)
{
	char	**map_pars;
	char	**map;

	map = NULL;
	map_pars = NULL;
	map_pars = copy_map(map_file, map_pars);
	map = copy_map(map_file, map_pars);
	if (!compo_check(map_pars) || !line_check(map_pars))
	{
		printf("compo %d\n", compo_check(map_pars));
		printf("line  %d\n", line_check(map_pars));
		return (0);
	}
	if (!line_size_check(map_pars) || !col_size_check(map_pars))
		return (0);
	if (!x_map(map_pars))
		return (0);
	if (!collect_check(map_pars))
		return (0);
	return (1);
}
