/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:01 by selee             #+#    #+#             */
/*   Updated: 2021/02/25 16:16:06 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (ptr[i] != '\0')
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	if (c == '\0' && ptr[i] == '\0')
		return (ptr);
	return (NULL);
}

char		*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*str;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	len_s1 = i;
	if (!(str = (char *)malloc(sizeof(char) * len_s1 + 1)))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	int		index;

	index = 0;
	if (!(str = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (index < n)
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

size_t		ft_strlcpy(char *restrict dst,
		const char *restrict src, size_t destsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (destsize > 0)
	{
		i = 0;
		while (src[i] && i < destsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	len_all;

	if (!s1 || !s2)
		return (NULL);
	len_all = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(dst = (char *)malloc(sizeof(char) * len_all)))
		return (NULL);
	i = 0;
	len_all = 0;
	if (s1)
	{
		while (s1[i])
			dst[len_all++] = s1[i++];
	}
	i = 0;
	if (s2)
	{
		while (s2[i])
			dst[len_all++] = s2[i++];
	}
	dst[len_all] = '\0';
	return (dst);
}

void		*ft_calloc(size_t count, size_t size)
{
	size_t	index;
	char 	*ptr;

	index = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (index < count)
	{
		ptr[index] = 0;
		index++;
	}
	return (ptr);
}
