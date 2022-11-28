/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_second.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:47:08 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/28 18:05:44 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strcmpchar(const char *s1,char c)
{
	size_t	i;

	i = 0;
	while (s1[i])
    {
        if (s1[i] == c)
        return (1);
    i++;
    }
	return (0);
}
