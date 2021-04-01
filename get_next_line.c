/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:23:37 by selee             #+#    #+#             */
/*   Updated: 2021/04/01 16:13:38 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char	*temp;
	char	buf[BUFFER_SIZE + 1];
	static char	*store;
	int		size_read;

	if ((fd < 0) || (!line) || (BUFFER_SIZE < 0))
		return (-1);
	if (!store)
		store = ft_strdup("");
	if (!(*line))
		*line = ft_strdup("");		
	size_read = read(fd, buf, BUFFER_SIZE);
	if (size_read < 0 )
		return (-1);
	while (size_read > 0)
	{
		temp = ft_strchr(buf, '\n');
		if (!temp)
		{
			*line = buf;
			return (1);
		}
		else if (temp)
		{	
			store = ft_strjoin(store, buf);
			printf("store = %s\n", store);
			*line = ft_strndup(store, store - buf);
			printf("line = %s\n", *line);
			free (store);
			store = temp + 1;
			printf("temp = %s\n", temp);
		return (1);
		}
	}
	return (0);
}

// need a funtion to return the string (line) and the number altogether.
// and a funtion to free

