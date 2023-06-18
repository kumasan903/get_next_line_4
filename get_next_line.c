/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:12:26 by skawanis          #+#    #+#             */
/*   Updated: 2023/06/14 03:38:04 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//#define BUFFER_SIZE 1

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*new_b;

	new_b = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		new_b[i] = (unsigned char)c;
		i++;
	}
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
		ft_memset(buf, '\0', BUFFER_SIZE + 1);
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == 0)
			break ;
		if (read_return < 0)
		{
			free(buf);
			return (1);
		}
		tmp = ft_strjoin(*memo, buf);
		free(*memo);
		*memo = tmp;
//		printf("memo:%s\nbuf :%s\nread_return:%ld\n", *memo, buf, read_return);
	}
	if (read_return == 0 && ft_strclen_s(*memo, '\0') == 0)
	{
		free(*memo);
		*memo = NULL;
	}
	free(buf);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*memo;
	char		*line;
	char		*tmp;

	if (memo && ft_strchr(memo, '\n'))
	{
//		puts("test1");
		line = ft_strcdup(memo, '\n');
		// MIN(FT_STRLEN, FT_STRCLEN + 1) ???
		tmp = ft_strcdup(memo + ft_strclen_s(memo, '\n') + 1, '\0');
		free(memo);
		memo = tmp;
		return (line);
	}
	else
	{
//		puts("test2");
		if (read_until_newline(&memo, fd) == 1)
			return (NULL);
		line = ft_strcdup(memo, '\n');
		if (memo)
		{
			tmp = ft_strcdup(memo + ft_strclen_s(memo, '\n') + 1, '\0');
			free(memo);
			memo = tmp;
		}
		return (line);
	}
}
