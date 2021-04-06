/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyounglee <seoyounglee@student.42lyon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:23:37 by selee             #+#    #+#             */
/*   Updated: 2021/04/06 15:09:35 by seoyounglee      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strjoin_free(char *s1, char *s2, int nb)
{
	char *dst;

	dst = ft_strjoin(s1, s2);
	if (nb == 1 || nb == 3)
		free (s1);
	if (nb == 2 || nb == 3)
		free (s2);
	return (dst);
}

int get_next_line(int fd, char **line)
{
	char	*new_line;
	char	buf[BUFFER_SIZE + 1];
	static char	*store;
	char 	*temp;
	int		size_read;

	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0))
		return (-1);
	if (!(store))
		store = ft_strdup("");
	size_read = read(fd, buf, BUFFER_SIZE);
	store = ft_strjoin_free(store, buf, 1);
	if (size_read < 0)
		return (-1);
	temp = NULL;
	new_line = ft_strchr(store, '\n');
	while (size_read > 0 && (!new_line))
	{
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read > 0)
		{
			store = ft_strjoin_free(store, buf, 1);
			new_line = ft_strchr(store, '\n');
		}
	}
	if (!(new_line))
	{
		*line = store;
		return (0);
	}
	if (new_line)
	{
		*line = ft_strndup(store, (ft_strlen(store) - ft_strlen(new_line)));
		temp = ft_strdup(new_line + 1);
		if (store)
			free (store);
		store = temp;
		return (1);
	}
	if (size_read < 0)
		return (-1);
	return (0);
}
