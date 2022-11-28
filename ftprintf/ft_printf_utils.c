/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:35:17 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/28 20:18:32 by roperrin         ###   ########.fr       */
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
		i += ft_putchar((n % 10) + '0');
	}
    return (1);
}

size_t	ft_putnbr_unsigned(unsigned int n)
{
    int i;
    
    i = 0;
	if (n == 4294967295)
    {
		ft_putstr("4294967295");
        return (11);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	i += ft_putchar((n % 10) + '0');
    return (i);
}

size_t	ft_putnbr_hexa(int n, int base)
{
    size_t 	i;
	char	base_min[16] = "0123456789abcdef";
	char	base_maj[16] = "0123456789ABCDEF";
	
    i = 0;
	if (n > 16)
	{
		ft_putnbr_hexa((n / 16), base);
	}
	if (base == 1)
		i += ft_putchar((base_min[(n % 16)]));
	if (base == 2)
		i += ft_putchar((base_maj[(n % 16)]));
    return (i);
}
