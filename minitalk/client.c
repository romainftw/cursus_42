/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:06:59 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/27 09:47:35 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receveid(char *str, int pid_n)
{
	int	bin;
	int	k;
	int	i;

	k = 7;
	i = 0;
	bin = 0;
	while (str[i])
	{
		while (k >= 0)
		{
			bin = (str[i] >> k & 1);
			if (bin == 1)
				kill(pid_n, SIGUSR1);
			if (bin == 0)
				kill(pid_n, SIGUSR2);
			k--;
			usleep(20);
		}
		k = 7;
		i++;
	}
}

int	main(int arc, char **arg)
{	
	//int		i;
	int		pid_n;

	//i = 7;
	if (arc == 3)
	{
		ft_printf("client start sa mere\n");
		pid_n = ft_atoi(arg[1]);
		receveid(arg[2], pid_n);
		ft_printf("client start sa mere\n");
		// while (i >= 0)
		// {
		// 	kill(pid_n, SIGUSR2);
		// 	i--;
		// }
	}
	return (0);
}
