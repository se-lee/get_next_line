/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:43:24 by selee             #+#    #+#             */
/*   Updated: 2021/03/02 15:50:51 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_line_index(char *line)
{
	int		index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	size_t		size_read;
	char		buf[BUFFER_SIZE];
	char		*temp;
	static char	*store;
	int			nl_index;

	if ((fd < 0) || (line == 0))
		return (-1);
	while ((size_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size_read] = '\0';
		store = ft_strjoin(*line, buf);
		nl_index = new_line_index(store);
		if (nl_index >= 0)
		{
			*line = ft_strndup(store, nl_index);
			temp = ft_strdup(store + nl_index);
			store = temp;
			return (1);
		}
	}
	return (0);
}
