/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:12:37 by skawanis          #+#    #+#             */
/*   Updated: 2023/06/06 14:47:07 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char		*uchar_src = (unsigned char *)src;
	unsigned char			*uchar_dst;
	size_t					i;

	uchar_dst = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		uchar_dst[i] = uchar_src[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	chr = (char)c;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == chr)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

size_t	ft_strclen_s(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	*ft_strcdup(const char *s1, int c)
{
	size_t	len;
	char	*dest;

	if (s1 == NULL)
		return (NULL);
	if (ft_strchr(s1, c))
	{
		len = ft_strclen_s(s1, c);
		dest = malloc(sizeof(char) * (len + 2));
		if (dest == NULL)
			return (NULL);
		dest[len + 1] = '\0';
		ft_memcpy(dest, s1, len + 1);
	}
	else
	{
		len = ft_strclen_s(s1, '\0');
		dest = malloc(sizeof(char) * (len + 1));
		if (dest == NULL)
			return (NULL);
		dest[len] = '\0';
		ft_memcpy(dest, s1, len);
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strcdup(s2, '\0'));
	if (s2 == NULL)
		return (ft_strcdup(s1, '\0'));
	s1_len = ft_strclen_s(s1, '\0');
	s2_len = ft_strclen_s(s2, '\0');
	dest = malloc(s1_len + s2_len + 1);
	if (dest == NULL)
		return (NULL);
	dest[s1_len + s2_len] = '\0';
	ft_memcpy(dest, s1, s1_len);
	ft_memcpy(dest + s1_len, s2, s2_len);
	return (dest);
}
