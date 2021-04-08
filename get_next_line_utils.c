/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:50:01 by selee             #+#    #+#             */
/*   Updated: 2021/04/08 14:28:06 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*str;
	int		i;

	len_s1 = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (!str)
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	i;
	size_t	len_all;

	if (!s1 || !s2)
		return (NULL);
	len_all = (ft_strlen(s1) + ft_strlen(s2) + 1);
	dst = (char *)malloc(sizeof(char) * len_all);
	if (!dst)
		return (NULL);
	i = 0;
	len_all = 0;
	while (s1[i])
		dst[len_all++] = s1[i++];
	i = 0;
	while (s2[i])
		dst[len_all++] = s2[i++];
	dst[len_all] = '\0';
	return (dst);
}

void	clean_free(void **data)
{
	free(*data);
	*data = NULL;
}