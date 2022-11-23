/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roperrin <roperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:33:22 by roperrin          #+#    #+#             */
/*   Updated: 2022/11/23 19:24:10 by roperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t	ft_strlen(const char *s)
{

	if (!s)
		return (0);
	size_t	i;

	i = 0;
while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{

	char	*str;
	size_t		len;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);

	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc(sizeof(char) * (len + 1));

	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	free(*s1);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n)
	{
		*p = '\0';
		p++;
		n--;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p != (char)c)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
