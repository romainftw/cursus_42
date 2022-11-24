/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:33:01 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/24 22:59:03 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_and_save(int fd, char *stockage)
{
	int		i;
	int		j;
	char	*buffer;
	
	j = 0;
	i = 1;
	stockage = ft_calloc(1,1);
	buffer = ft_calloc(BUFFER_SIZE, 1);
	while (i || !ft_strchr(stockage, '\n'))
	{
		buffer = ft_calloc(BUFFER_SIZE, 1);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return(NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		stockage = ft_strjoin(stockage, buffer);
		free(buffer);
	}
		buffer[BUFFER_SIZE] = '\0';
		stockage = ft_strjoin(stockage, buffer);
		return (stockage);
}

char *ft_cut_and_move(char *buffer, char* str)
{
	int i;
	int j;
	
	j = 0;
	i = ft_strlen(buffer);
	str = ft_calloc(i , sizeof(char));
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
	
	printf("%s\n", stockage);
	str = malloc(sizeof(char) * ft_strlen(stockage));
	str = ft_cut_and_move(stockage, str);
	free(stockage);
	return(str);
}

int main(void)
{
	int fd = open("test.txt", O_RDONLY);

	char *line;
	//while(1)
	//{
		line =  get_next_line(fd);
		//if (line == NULL)
		//	break;
		printf ("%s",line );
	//}
	 return 0;
}
