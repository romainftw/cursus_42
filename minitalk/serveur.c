/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:05:45 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/27 00:06:39 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convertion(int sign)
{
	static char	x = 0;
	static int	i = 0;

	if (sign == 30)
		x = (x << 1 | 1);
	if (sign == 31)
		x = (x << 1 & ~0);
	i++;
	if (i == 8)
	{
		ft_printf("%c", x);
		i = 0;
		x = 0;
	}
}

int	main(void)
{
	int	pid_n;

	pid_n = getpid();
	ft_printf("PID : %d\n", pid_n);
	signal(SIGUSR1, convertion);
	signal(SIGUSR2, convertion);
	while (1)
	{
	}
	return (0);
}