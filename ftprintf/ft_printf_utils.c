/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:35:17 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/26 15:19:48 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t    ft_putchar(char c)
{
	write(1, &c, 1);
    return (1);
}

size_t	ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (s)
		while (s[i])
			write(1, &s[i++], 1);
    return (i);
}

size_t	ft_putnbr(int n)
{
    int i;
    
    i = 0;
	if (n == -2147483648)
    {
		ft_putstr("-2147483648");
        return (11);
    }
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * -1;
            i += 1;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
        i += 1;
		ft_putchar((n % 10) + '0');
	}
    return (i);
}
