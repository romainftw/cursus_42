/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:06:59 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/28 15:54:30 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receveid(char c, int pid_n)
{
	int	bin;
	int	k;

	k = 7;
	bin = 0;

		while (k >= 0)
		{
			bin = (c >> k & 1);
			if (bin == 1)
				kill(pid_n, SIGUSR1);
			if (bin == 0)
				kill(pid_n, SIGUSR2);
			k--;
						usleep(500);
		}
	//  k = 7;
	//  while (k >= 0)
	//  {
	//  	ft_printf("- ");
	//  	kill(pid_n, SIGUSR2);
	//  	k--;
	//  }
}

int	main(int arc, char **arg)
{	
	int		i;
	int		pid_n;

	i = 0;
	if (arc == 3)
	{
		ft_printf("client start sa mere\n");
		pid_n = ft_atoi(arg[1]);
		while (arg[2][i])
		{
			receveid(arg[2][i], pid_n);
			i++;
		}
		ft_printf("client start sa mere\n");
	}
	return (0);
}
