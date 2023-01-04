/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:28:33 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/04 14:17:16 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	pars_one(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("FILE PROBLEM");
		return (0);
	}
	while ()
	{
		/* code */
	}
	
	return (0);
}
