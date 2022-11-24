/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r <r@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:33:01 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/24 14:57:03 by r                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_and_save(int fd, char *str)
{
	int		i;
	char	*buffer;
	
	i = 0;
	buffer = malloc(sizeof(BUFFER_SIZE + 1));
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return(NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		
			ft_strjoin(str, buffer);	
	}
	return (str);
}

char *ft_cut_and_move(int fd,char *buffer, char* str)
{
	int i;
	int j;
	
	j = 0;
	printf("test2\n");
	i = ft_strlen(buffer);
	read(fd, buffer, BUFFER_SIZE);
	str = ft_calloc(i + 2, sizeof(char));
	while (i)
	{
		str[j] = buffer[j];
		i--;
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
	str = malloc(sizeof(char) * ft_strlen(stockage));
	printf("%s\n", stockage);
	printf("test1\n");
	str = ft_cut_and_move(fd, stockage, str);
	printf("test3\n");
	printf("%s\n", stockage);
	free(stockage);
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
