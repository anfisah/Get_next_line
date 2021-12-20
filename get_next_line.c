/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:57:52 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/04 15:18:58 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = malloc((size * count))))
		return (NULL);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

char	*read_line(int fd, char *str, int *res)
{
	char	buf[BUFFER_SIZE + 1];

	if (ft_memchr(str, '\n') == 1)
		return (str);
	while ((*res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[*res] = '\0';
		str = ft_strjoin(str, buf);
		if ((ft_memchr(str, '\n') == 1))
			break ;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	int			i;
	static char	*str;

	i = 0;
	res = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL || (read(fd, 0, 0) < 0))
		return (-1);
	if (res == -1)
		return (-1);
	if (str == NULL)
		str = ft_calloc(1, 1);
	str = read_line(fd, str, &res);
	while (str[i] && str[i] != '\n')
		i++;
	(*line) = ft_substr(str, 0, i);
	str = ft_substr2(str, i + 1, (ft_strlen(str) - i) - 1);
	if (*str == 0 && res == 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	return (1);
}
