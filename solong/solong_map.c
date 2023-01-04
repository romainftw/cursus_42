/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:05:58 by roperrin          #+#    #+#             */
/*   Updated: 2023/01/04 18:26:31 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**map_size(char *map)

{
	int		fd;
	int		i;
	char	*line;
	char	**save_map;

	i = 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("FILE PROBLEM");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	save_map = malloc(sizeof(char *) * i);
	close(fd);
	return (save_map);
}

char	**copy_map(char *map_file, char **map)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(map_file, O_RDONLY);
	map = map_size(map_file);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i++] = ft_strtrim(line, "\n");
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

int	compo_check(char **map)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && (map[i][j] != '0')
					&& (map[i][j] != 'C')
						&& (map[i][j] != 'P')
							&& (map[i][j] != 'E'))
				return (0);
			if (map[i][j] == 'P' || map[i][j] == 'E')
				k++;
			j++;
		}
		i++;
	}
	if (k > 2)
		return (0);
	return (1);
}

int	line_check(char **map)
{
	int	len_line;
	int	i;

	i = 0;
	len_line = ft_strlen(map[0]);
	if (ft_strchr(map[0], '1'))
		return (0);
	//while (map[i])
	//{
		
	//}
	return (1);
}
