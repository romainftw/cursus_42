/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <r@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:51:30 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/15 15:09:56 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;

	if (!dst && !src)
		return (NULL);
	s1 = (char *)dst;
	while (n)
	{
		*(char *)s1 = *(char *)src;
		s1++;
		src++;
		n--;
	}
	return (dst);
}
