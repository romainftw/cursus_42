/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:33:01 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/24 23:47:13 by roperrin         ###   ########.fr       */
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

char *ft_read_and_save(int fd, char *stockage)
{
	int		i;
	int		j;
	char	*buffer;
	
	j = 0;
	i = 1;
	stockage = ft_calloc(1,1);
	buffer = ft_calloc(BUFFER_SIZE, 1);
	while (!ft_strchr(stockage, '\n'))
	{
		buffer = ft_calloc(BUFFER_SIZE, 1);
		i = read(fd, buffer, BUFFER_SIZE);
		stockage = ft_strjoin(stockage, buffer);
		free(buffer);
		if (i == -1)
		{
			free(buffer);
			return(NULL);
		}
		if (i == 0)
		{
			stockage = ft_strjoin(stockage, buffer);
			return (stockage);		
		}	
	}
		return (stockage);
}

char *ft_cut_and_move(char *buffer, char* str)
{
	int i;
	int j;
	
	j = 0;
	i = ft_strlen(buffer);
	str = ft_calloc(i , sizeof(char));
	while (buffer[j] != '\n')
	{
		str[j] = buffer[j];
		i--;
		j++;
	}
	str[j++] = '\n';
	str[j++] = '\0';
	
	return (str);
}

char *get_next_line(int fd)
{
	char				*str;
	static char			*stockage;
	
	if (!fd)
		return (NULL);
		
	stockage = ft_read_and_save(fd, stockage);
	
	str = ft_calloc(1,1);
	str = ft_cut_and_move(stockage, str);
	stockage = ft_substr(stockage, ft_strlen(str), (ft_strlen(stockage) - ft_strlen(str)));
	return(str);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);

	char *line;
	while(1)
	{
		line =  get_next_line(fd);
		if (line == NULL)
			break;
		printf ("%s",line );
	}
	 return 0;
}
