/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:05:45 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/27 16:38:15 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convertion(int sign)
{
	static char	*str = "";
	static char	x = 0;
	static int	i = 0;

	if (sign == 30)
		x = (x << 1 | 1);
	if (sign == 31)
		x = (x << 1 & ~0);
	i++;
	if (i == 8)
	{
		str = ft_strjoin_char(str, x);
		i = 0;
		if (x == 0)
		{
			ft_printf("%s\n", str);
			free(str);
		}
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
