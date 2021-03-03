/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:43:24 by selee             #+#    #+#             */
/*   Updated: 2021/03/03 15:13:32 by selee            ###   ########lyon.fr   */
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

int		split_line(

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
		*line = ft_strdup("");
		store = ft_calloc(size_read, sizeof(char));
		dprintf(1, "1. line = %s\n", *line);
		dprintf(1, "2. buf = %s\n", buf);
		store = ft_strchr(buf, ('\n'));
		dprintf(1, "3. store = %s\n", store);
		nl_index = new_line_index(store);
		if (nl_index >= 0)
		{
			*line = ft_strndup(store, nl_index);
			temp = ft_strdup(store + nl_index);
			store = temp;
		}
		return (1);
	}
	return (0);
}
