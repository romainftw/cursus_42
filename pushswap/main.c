/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:22:30 by roperrin          #+#    #+#             */
/*   Updated: 2023/02/20 13:24:21 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arc, char **arg)
{
	t_slack	ctx;
	if (arc > 1)
		parsing(arg, arc, &ctx);
	//system("leaks push_swap");
	return (0);
}
