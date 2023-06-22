/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:33:01 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/25 21:28:34 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = -1;
	if (!s[0])
	{
		free(s);
		return (0);
	}
	if (len > ft_strlen(s))
		len = (ft_strlen(s) - start);
	if (start > ft_strlen(s))
		len = 0;
	p = malloc(sizeof(char) * (len) + 1);
	if (!p)
	{
		free(s);
		return (NULL);
	}
	while (++i < len)
		p[i] = s[start + i];
	p[i] = '\0';
	free (s);
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
		{
			free (stockage);
			return (NULL);
		}
		buffer[i] = '\0';
		stockage = ft_strjoin(stockage, buffer);
		if (!stockage)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stockage);
}

char	*ft_cut_and_move(char *buffer, char *str)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(buffer);
	if (!buffer[j])
		return (NULL);
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
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

char	*get_next_line(int fd)
{
	char				*str;
	static char			*stockage = NULL;
	size_t				len_str;

	if (fd < 0)
	{
		if (stockage)
		{
			free(stockage);
			stockage = NULL;
		}
	}
	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stockage = ft_read_and_save(fd, stockage);
	if (!stockage)
		return (NULL);
	str = ft_cut_and_move(stockage, str);
	len_str = ft_strlen(str);
	stockage = ft_substr(stockage, len_str, (ft_strlen(stockage) - len_str));
	if (!stockage && !str)
		return (NULL);
	return (str);
}
