/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:43:24 by selee             #+#    #+#             */
/*   Updated: 2021/03/08 16:13:07 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_line_index(char *store)
{
	int		index;

	index = 0;
	if (store == NULL)
		store = ft_strdup("");
	while (store[index])
	{
		if (store[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

/*
int		split_line(char **store, char **line, int nl_index)
{
	char	*temp;
	int		len;

	(*store)[nl_index] = '\0';
	*line = ft_strdup(*store);
	len = ft_strlen(*store + nl_index + 1);
	if (len == 0)
	{
		free(*store);
		*store = 0;
		return (1);
	}
	temp = ft_strdup(*store + nl_index + 1);
	free(*store);
	*store = temp;
	return (1);
}

int		return_all(char **store, char **line, int size_read)
{
	int		nl_index;

	if (size_read < 0)
		return (-1);
	if (*store && (nl_index = new_line_index(*store)) >= 0)
		return (split_line(store, line, nl_index));
	else if (*store)
	{
		*line = *store;
		*store = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*store[OPEN_MAX];
	char			buf[BUFFER_SIZE];
	int				size_read;
	int				nl_index;

	if ((fd < 0 ) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((size_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size_read] = '\0';
		dprintf(1, "buf = %s\n", buf);
		store[fd] = ft_strjoin(store[fd], buf);
		dprintf(1, "line = %s\n", *line);
		dprintf(1, "store = %s\n", *store);
		if ((nl_index = new_line_index(store[fd])) >= 0)
			return (split_line(&store[fd], line, nl_index));
	}
	return (return_all(&store[fd], line, size_read));
}

*/

// 08-03-2021 15:50

int		get_next_line(int fd, char **line)
{
	size_t		size_read = 0;
	char		buf[BUFFER_SIZE];
	char		*temp;
	static char	*store[OPEN_MAX];
	int			nl_index;

	if ((fd < 0) || (line == 0))
		return (-1);
	while ((size_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size_read] = '\0';
		*store = ft_strdup(buf);
		nl_index = new_line_index(*store);
		dprintf(1, "0. nl_index = %d\n", nl_index);
		dprintf(1, "0. line = %s\n", *line);
		dprintf(1, "0. buf = %s\n", buf);
		dprintf(1, "0. store = %s\n", *store);
		if (nl_index > 0)
		{
			*store[nl_index] = '\0';
			*line = ft_strdup(*store);
			dprintf(1, "4. line = %s\n", *line);
			temp = ft_strdup(*store + nl_index + 1);
			*store = temp;
			dprintf(1, "6. store = %s\n", *store);
			dprintf(1, "7. buf = %s\n", buf);
		}
		return (1);
	}
	return (0);
}
