/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:59:39 by ccoto             #+#    #+#             */
/*   Updated: 2020/12/03 11:58:05 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_memchr(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr2(char *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
char	*read_line(int fd, char **str, int *res);

#endif
