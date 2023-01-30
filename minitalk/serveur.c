/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:05:45 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/30 13:23:35 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convertion(int sign)
{
	static char	*str = "\0";
	static char	x = 0;
	static int	i = 0;
	char		*temp;

	if (sign == 30)
		x = (x << 1 | 1);
	if (sign == 31)
		x = (x << 1 & ~0);
	i++;
	if (i == 8)
	{
		temp = str;
		str = ft_strjoin_char(temp, x);
		//free (temp);
		i = 0;
		if (!x)
		{
			ft_printf("%s", str);
			str = "";
		}
		x = 0;
	}
}

int	main(void)
{
	int	pid_n;

	pid_n = getpid();
	ft_printf("PID : %d\n", pid_n);
	while (1)
	{
	signal(SIGUSR1, convertion);
	signal(SIGUSR2, convertion);
	pause();
	}
	return (0);
}