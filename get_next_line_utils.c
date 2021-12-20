/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:02:06 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/03 09:51:23 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = 0;
	if (s1)
		free((char *)s1);
	return (s3);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	index = 0;
	while (index < len && ((index + start) < size))
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

int		ft_memchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	index = 0;
	while (index < len && ((index + start) < size))
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	free((char *)s);
	return (str);
}
