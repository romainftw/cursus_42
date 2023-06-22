/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:35:17 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/27 00:04:32 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	*count += 1;
	write(1, &c, 1);
}

void	ft_putstr(char const *s, int *count)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i], count);
			i++;
		}
	}
	else
		ft_putstr("(null)", count);
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", count);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', count);
			n = n * -1;
		}
		if (n > 9)
			ft_putnbr((n / 10), count);
		ft_putchar(((n % 10) + '0'), count);
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n >= 10)
		ft_putnbr((n / 10), count);
	ft_putchar(((n % 10) + '0'), count);
}

void	ft_putnbr_hexa(unsigned int n, int base, int *count)
{
	char	*base_min;
	char	*base_maj;

	base_min = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_putnbr_hexa((n / 16), base, count);
		ft_putnbr_hexa((n % 16), base, count);
	}
	else
	{
		if (base == 1)
			ft_putchar(((base_min[(n % 16)])), count);
		if (base == 2)
			ft_putchar(((base_maj[(n % 16)])), count);
	}
}
