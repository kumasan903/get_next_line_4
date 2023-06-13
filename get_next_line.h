/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:12:42 by skawanis          #+#    #+#             */
/*   Updated: 2023/06/13 16:22:23 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strclen_s(const char *s, int c);
char	*ft_strcdup(const char *s1, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*get_next_line(int fd);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif
