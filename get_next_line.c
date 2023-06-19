/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:12:26 by skawanis          #+#    #+#             */
/*   Updated: 2023/06/20 03:52:00 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	free_and_null(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	read_until_newline(char **memo, int fd)
{
	char	*buf;
	ssize_t	read_return;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	buf[BUFFER_SIZE] = '\0';
	while (!*memo || !ft_strchr(*memo, '\n'))
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == 0)
			break ;
		if (read_return < 0)
		{
			free(buf);
			return (1);
		}
		buf[read_return] = '\0';
		tmp = ft_strjoin(*memo, buf);
		free(*memo);
		*memo = tmp;
	}
	if (read_return == 0 && ft_strclen_s(*memo, '\0') == 0)
		free_and_null(memo);
	free(buf);
	return (0);
}

char	*cut_memo(char **memo)
{
	char	*line;
	char	*tmp;

	line = ft_strcdup(*memo, '\n');
	tmp = ft_strcdup(*memo + ft_min(ft_strclen_s(*memo, '\0'),
				ft_strclen_s(*memo, '\n') + 1), '\0');
	free(*memo);
	*memo = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*memo;
	char		*line;
	char		*tmp;

	if (memo && ft_strchr(memo, '\n'))
	{
		line = cut_memo(&memo);
		return (line);
	}
	else
	{
		if (read_until_newline(&memo, fd) == 1)
			return (NULL);
		line = ft_strcdup(memo, '\n');
		if (ft_strclen_s(memo, '\0') == ft_strclen_s(line, '\0'))
			free_and_null(&memo);
		if (memo)
		{
			tmp = ft_strcdup(memo + ft_strclen_s(memo, '\n') + 1, '\0');
			free(memo);
			memo = tmp;
		}
		return (line);
	}
}
