/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:50:38 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/20 14:15:30 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (size >= SIZE_MAX || count >= SIZE_MAX)
		return (0);
	s = malloc(size * count);
	if (!s)
		return (0);
	ft_memset(s, 0, count * size);
	return (s);
}
