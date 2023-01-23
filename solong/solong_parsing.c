/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:28:33 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/23 13:32:12 by roperrin         ###   ########.fr       */
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
		return (0);
	if (!line_size_check(map_pars) || !col_size_check(map_pars))
		return (0);
	if (!x_map(map_pars))
		return (0);
	if (!collect_check(map_pars))
		return (0);
	return (1);
}

int	check_extension(char **arg)
{
	int	len;

	len = ft_strlen(arg[1]);
	if (arg[1][len - 1] == 'r')
		if (arg[1][len - 2] == 'e')
			if (arg[1][len - 3] == 'b')
				if (arg[1][len - 4] == '.')
					return (1);
	ft_printf("ERROR\nMAP FILE INVALIDE :'( ");
	return (0);
}
