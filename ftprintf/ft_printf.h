/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:35:56 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/28 23:51:11 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

size_t	ft_putchar(char c);
size_t	ft_putnbr(int n);
size_t	ft_putstr(char const *s);
size_t  ft_print_arg(va_list *lst,const char *s);
size_t	ft_putnbr_unsigned(unsigned int n);
size_t	ft_putnbr_hexa(int n, int base);
int     ft_printf(const char *str, ...);
int     ft_strcmpchar(const char *s1,char c);
int     ft_check(char input);
int     ft_check(char input);

#endif