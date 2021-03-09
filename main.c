/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:55:01 by selee             #+#    #+#             */
/*   Updated: 2021/03/09 13:23:09 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;

//	while (1)
//	{
	fd = open("your_file_name", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("main: %s\n", line);
		free(line);
	}
	printf("main2: %s\n", line);
	free(line);
	line = NULL;
	close(fd);
//	}
	return (0);
}
