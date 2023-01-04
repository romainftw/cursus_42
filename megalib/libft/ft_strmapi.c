/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:48:15 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/15 20:18:20 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = f(i, s[i]);
		++i;
	}
	p[i] = '\0';
	return (p);
}
