/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:05:45 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/30 15:21:33 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_str;

void	print(void)
{
	ft_printf("%s", g_str);
	if (g_str)
	{
		free (g_str);
		g_str = malloc(1);
		g_str[0] = '\0';
	}
}

void	convertion(int sign)
{
	static char	x = 0;
	static int	i = 0;
	char		*tmp;

	if (!g_str)
	{
		g_str = malloc(1);
		g_str[0] = '\0';
	}
	if (sign == 30)
		x = (x << 1 | 1);
	if (sign == 31)
		x = (x << 1 & ~0);
	i++;
	if (i == 8)
	{
		tmp = ft_strjoin_char(g_str, x);
		if (g_str)
			free(g_str);
		g_str = tmp;
		i = 0;
		if (!x)
			print();
		x = 0;
	}
}

void	test(int sign)
{
	(void) sign;
	free(g_str);
	exit(0);
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
		signal(SIGINT, test);
		pause();
	}
	return (0);
}
