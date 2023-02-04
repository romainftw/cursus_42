/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:22:30 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/04 17:42:01 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arg)
{
	if (arc > 1)
		parsing(arg, arc);
	else
		ft_printf("Error\n");
	//system("leaks push_swap");
	return (0);
}
