/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:33:01 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/23 19:24:53 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char				*str;
	static char			*stockage;
	static unsigned int		count;
	static unsigned int		i;
	
	count += i;
	i = 0;
	if (!fd)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	stockage = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_bzero(str, (size_t)BUFFER_SIZE);

	stockage = ft_fd_to_stockage(fd, BUFFER_SIZE, stockage);
	while(stockage)
	{
		if (stockage[i + count] == '\n' || (stockage[i + count]))
		{
			str = ft_substr(stockage, i, (size_t)(count - i));
			return(str);
		}
		i++;
	}
	return(str);
}

int main()
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
