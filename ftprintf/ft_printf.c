/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:01:41 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/26 15:22:13 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_arg(char *s)
{
    int count;
    int i;

    count = 0;
    i = 0;
    //while (s[i])
   // {
    
    //if (s[i] == '%' && s[i] == 'c')
       ft_putchar((char)s);
       i++;
       
   // }
    //count = i;
    return (count);
}

int ft_printf(const char *s, ...)
{
    va_list lst;
    int count;
    
    count = 0;
    va_start(lst, s);
    count = ft_print_arg(va_arg(lst, char*));

    va_end(lst);
    return (count);
}

int main(void)
{
    ft_printf("nhg");
    
    return(0);
}