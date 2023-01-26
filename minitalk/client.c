/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:06:59 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/26 17:33:08 by roperrin         ###   ########.fr       */
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
			usleep(5000);
		}
		k = 7;
		i++;
	}
}

int	main(int arc, char **arg)
{	
	int		i;
	int		pid_n;

	i = 1;
	if (arc >= 2)
	{
		ft_printf("client start sa mere\n");
		pid_n = ft_atoi(arg[i]);
		i++;
		while (arg[i])
		{
			receveid(arg[i], pid_n);
			i++;
		}
	}
	return (0);
}
