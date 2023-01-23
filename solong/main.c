/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:07:15 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/23 14:50:23 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int arc, char **arg)
{
	if (arc != 2)
		return (0);
	if (open(arg[1], O_RDONLY) < 0)
	{
		perror("ERROR\n");
		return (0);
	}
	if (!check_extension(arg))
		return (0);
	if (!pars_first(arg[1]))
		ft_printf("ERROR\nmap composition");
	return (0);
}
