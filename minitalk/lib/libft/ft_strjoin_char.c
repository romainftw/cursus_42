/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:15:19 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/27 13:48:11 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *s1, char c)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = (ft_strlen(s1));
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
		return (0);
	if (s1)
	{
		while (i < len)
		{
			str[i] = s1[i];
			i++;
		}
	}
	str[i] = c;
	i++;
	str[i] = '\0';
	return (str);
}
