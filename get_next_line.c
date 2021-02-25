/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:43:24 by selee             #+#    #+#             */
/*   Updated: 2021/02/25 16:16:02 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_line_index(char *line)
{
	int		index;

	index = 0;
	while ((line[index] != '\0') && (line[index] != '\n'))
		index++;
	return (index);
}

/*
int		get_next_line(int fd, char **line)
{
	size_t		size_read;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	static char	*store;
	int			nl_index;
	int			len;

	if ((fd < 0) || (line == 0))
		return (-1);
	while ((size_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size_read] = '\0';
		store = ft_strjoin(store, buf);
		if ((nl_index = new_line_index(buf)) >= 0)
		{
			*line = ft_strdup(store);
			len = ft_strlen(store + nl_index + 1);
			if (len == 0)
			{
				free(store);
				store = 0;
				return (1);
			}
			temp = ft_strdup(store + nl_index + 1);
			free(store);
			store = temp;
			return (1);
		}
	}
	return (0);
}
*/

int		get_next_line(int fd, char **line)
{
	size_t		size_read;
	char		buf[BUFFER_SIZE + 1];
	static char	*store;
	char		*temp;
	int			line_len;

	if ((fd < 0) || (line == 0))
		return (-1);
	size_read = read(fd, buf, BUFFER_SIZE);
	while (size_read > 0)
	{
		buf[size_read] = '\0';
		line_len = new_line_index(buf);
		temp = ft_strndup(buf, line_len);
		store = ft_calloc((size_read - line_len) + 1, sizeof(char));
		store = ft_strchr(buf, '\n');
		return (1);
	}
	return (0);
}
