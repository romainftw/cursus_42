/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:06:59 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/26 12:27:55 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receveid(char *str)
{
	ft_printf("%s", str);
}

int	main(int arc, char **arg)
{	
	int	i;

	i = 1;
	if (arc >= 2)
	{
		ft_printf("client start ta mere\n");
		while (arg[i])
		{
			receveid(arg[i]);
			i++;
		}
	}
	return (0);
}
