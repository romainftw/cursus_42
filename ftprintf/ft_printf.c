/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:16:34 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/29 00:55:13 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check(char input)
{
    char    flag[10] = "csdiuxXp%";

        if (ft_strcmpchar(flag, input))
            return(1);
    return (0);
}

size_t ft_print_arg(va_list *lst,const char *s)
{
    size_t  i;
    size_t  count;

    count = 0;
    i = 1;
    if (s[i] == 'c')
        count += ft_putchar(va_arg(*lst, int));
    if (s[i] == 's')
        count += ft_putstr(va_arg(*lst, char *));
    if (s[i] == 'i' || s[i] == 'd')
        count += ft_putnbr(va_arg(*lst, int));
    if (s[i] == 'u')
        count += ft_putnbr_unsigned(va_arg(*lst, unsigned int));
    if (s[i] == 'x')
        count += ft_putnbr_hexa(va_arg(*lst, int), 1);
    if (s[i] == 'X')
        count += ft_putnbr_hexa(va_arg(*lst, int), 2);
    if (s[i] == 'p')
        count += ft_putchar('%');
    if (s[i] == '%')
        count += ft_putchar('%');
    return (count);
}

int ft_printf(const char *str, ...)
{
    va_list lst;
    size_t  i;
    size_t  count;
    
    i = 0;
    count = 0;
    va_start(lst, str);
    while (str[i])
    {
        if (str[i] == '%')
            if (!ft_check(str[i++]))
                return (0);
        i++;
    }
    i = 0;
    while (str[i])
    {
            if (str[i] == '%')
            {
                count += ft_print_arg(&lst, &str[i]);
                i += 1;
            }
            else
            count += ft_putchar(str[i]);
            i++;
    }
    va_end(lst);
    return (count);
}

/*
int main(void)
{
    printf("\n%d\n" ,ft_printf("%d%sXXXX XXXX", 10, " TASMERE"));

    return(0);
}
*/