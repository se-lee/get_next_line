/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:43:24 by selee             #+#    #+#             */
/*   Updated: 2021/03/09 16:15:02 by selee            ###   ########lyon.fr   */
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
	return (index);
}

char	*read_file(int fd, char *store)
{
	size_t	size_read;
	char	*temp;
	char	buf[BUFFER_SIZE + 1];

	while ((size_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size_read] = '\0';
		if (store == NULL)
			store = ft_strdup("");
		temp = ft_strjoin(store, buf);
		free(store);
		store = temp;
	}
	return (store);
}

int		get_next_line(int fd, char **line)
{
	char		*temp;
	static char	*store;
	int			nl_index;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	if (!(store = read_file(fd, store)))
		return (-1);
	nl_index = new_line_index(store);
	if (store[nl_index] == 0)
	{
		*line = store;
		return (0);
	}
	if (nl_index >= 0)
	{
		store[nl_index] = '\0';
		*line = ft_strdup(store);
		temp = ft_strdup(&store[nl_index + 1]);
		free(store);
		store = temp;
		return (1);
	}
	return (0);
}
