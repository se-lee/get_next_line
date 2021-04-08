/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:23:37 by selee             #+#    #+#             */
/*   Updated: 2021/04/08 14:34:29 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	var_init(char **store, int	*size_read, char **new_line)
{
	if (!*store)
		*store = ft_strdup("");
	*size_read = 1;
	*new_line = ft_strchr(*store, '\n');
}

void	append_string(char **str_pointer, const char *to_append)
{
	char	*str;

	str = *str_pointer;
	*str_pointer = ft_strjoin(str, to_append);
	free(str);
}

int	return_result(char *new_line, char **store, char **line)
{
	char	*temp;

	if (new_line)
	{
		*new_line = '\0';
		*line = ft_strdup(*store);
		temp = ft_strdup(new_line + 1);
		if (*store)
			free(*store);
		*store = temp;
		return (1);
	}
	*line = ft_strdup(*store);
	clean_free((void **)store);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*new_line;
	char		buf[BUFFER_SIZE + 1];
	static char	*store = NULL;
	int			size_read;

	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0))
		return (-1);
	var_init(&store, &size_read, &new_line);
	while (size_read > 0 && !new_line)
	{
		size_read = 0;
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read < 0)
		{
			clean_free((void **)&store);
			return (-1);
		}
		buf[size_read] = '\0';
		append_string(&store, buf);
		new_line = ft_strchr(store, '\n');
	}
	return (return_result(new_line, &store, line));
}
