/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <r@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:33:01 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/25 15:21:33 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = (ft_strlen(s) - start);
	if (start > ft_strlen(s))
		len = 0;
	p = malloc(sizeof(char) * (len) + 1);
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_read_and_save(int fd, char *stockage)
{
	int		i;
	char	buffer[BUFFER_SIZE + 1];
	
	i = 1;
	if (!stockage)
		stockage = ft_calloc(1, 1);
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return(NULL);
		buffer[i] = '\0';
		stockage = ft_strjoin(stockage, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
		return (stockage);
}

char *ft_cut_and_move(char *buffer, char* str)
{
	int i;
	int j;
	
	j = 0;
	i = ft_strlen(buffer);
	str = ft_calloc(i + 2, sizeof(char));
	while (buffer[j] != '\n' && buffer[j])
	{
		str[j] = buffer[j];
		j++;
	}
	if (!buffer[j])
		str[j] = '\0';
	else
		str[j] = '\n';
	str[++j] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	char				*str;
	static char			*stockage;
	
	if (!fd || fd < 0)
		return (NULL);
	stockage = ft_read_and_save(fd, stockage);
	str = ft_calloc(1,1);
	str = ft_cut_and_move(stockage, str);
	stockage = ft_substr(stockage, ft_strlen(str), (ft_strlen(stockage) - ft_strlen(str)));
	return(str);
}


