/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:01:41 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/26 19:34:46 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_print_arg(va_list lst,const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '%')
            {
                i++;
                if (s[i] == "c")
                    ft_putchar(s[i++]);
                if (s[i] == "s")
                    ft_putstr(s[i++]);
            }
        i++;
    }
    return (i);
}

int ft_printf(const char *s, ...)
{
    va_list lst;
    size_t count;
    
    count = 0;
    va_start(lst, s);
    count = ft_print_arg(lst, s);

    va_end(lst);
    return (count);
}

int main(void)
{
    ft_printf("");
    
    return(0);
}