/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:05:45 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/29 19:07:21 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_str(char *str_bin, int carnul)
{
	static char	*str = "";
	static char	x = 0;
	int			i;

	i = 0;
	while (str_bin[i] <= 7)
	{
		if (str_bin[i] == 1)
			x = (x << 1 | 1);
		if (str_bin[i] == 0)
			x = (x << 1 & ~0);
		i++;
	}
	str = ft_strjoin_char(str, x);
	x = 0;
	if (carnul == 8)
	{
		ft_printf("%s\n", str);
		str = "";
	}
	ft_printf("%s\n", str);
}

void	convertion(int sign)
{
	char	*str;
	int		i = 7;
	int		x;

	x = 0;
	str = malloc(sizeof(char) * 8);
	while (str[i])
	{
		if (sign == 30)
			str[i] = '1';
		if (sign == 31)
		{
			str[i] = '0';
			x++;
		}
		i--;
	}
	str[8] = '\0';
	print_str(str, x);
	free(str);
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
