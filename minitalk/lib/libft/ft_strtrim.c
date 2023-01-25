/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:28:34 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/15 19:31:25 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static int	find_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	find_end(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i])
	{
		if (ft_strchr(set, s1[len - 1]) == 0)
			break ;
		len--;
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		diff;
	char	*new_str;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	end = (find_end(s1, set));
	diff = (end - start);
	if (end <= start)
		diff = 0;
	new_str = malloc(sizeof(char) * diff + 1);
	if (!new_str)
		return (NULL);
	while (start < end)
	{
		new_str[i++] = s1[start++];
	}
	new_str[i] = '\0';
	return (new_str);
}
