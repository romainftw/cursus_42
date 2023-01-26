/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:15:19 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/26 22:50:25 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *s1, char c)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !c)
		return (0);
	len = (ft_strlen(s1));
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	i++;
	str[i] = '\0';
	return (str);
}
