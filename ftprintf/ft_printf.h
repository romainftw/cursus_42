/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:35:56 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/29 17:48:30 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

void     ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putstr(char const *s, int *count);
int     ft_print_arg(va_list *lst,const char *s ,int *count);
void	ft_putnbr_unsigned(unsigned int n, int *count);
void	ft_putnbr_hexa(unsigned int n, int base, int *count);
int     ft_printf(const char *str, ...);
int     ft_strcmpchar(const char *s1,char c);
int     ft_check(char input);

#endif