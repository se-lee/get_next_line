/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:43:24 by selee             #+#    #+#             */
/*   Updated: 2021/03/29 16:05:21 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int new_line_index(char *store)
{
    int     index;

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

char    *read_file(int fd, char **store, int *nl_index, int *size_read)
{
    char    *temp;
    char    buf[BUFFER_SIZE + 1];

    *size_read = 0; //if read(fd..) doesnt work i should have some value in size_read. so set it to 0;
    *size_read = read(fd, buf, BUFFER_SIZE);
	if (*size_read < 0)
		return (NULL);
	else if (*size_read == 0)
		return (*store);
    while (*size_read > 0)
    {
        buf[*size_read] = '\0';
        if(*store == NULL)
            *store = ft_strdup("");
        temp = ft_strjoin(*store, buf);
		if (*store)
	        free(*store);
        *store = temp;
        *nl_index = new_line_index(*store);  //if no *, it is not pointing
        if (*nl_index)
            break;
        *size_read = read(fd, buf, BUFFER_SIZE);
    }
    return (*store);
}

int get_next_line(int fd, char **line)
{
    char        *temp;
    static char *store;
    int         nl_index;
	int			size_read;

    if ((fd < 0) || line == 0 || (BUFFER_SIZE <= 0))
        return (-1);
    if (!(store))
        store = ft_strdup("");
	//condition : if there's a \n in store then it shouldn't do the next line
	nl_index = new_line_index(store);
	if (nl_index < 0) // if no newline
	{
	    store = read_file(fd, &store, &nl_index, &size_read);
	    if (store == NULL)
	        return (-1);
		if (size_read == 0) //end of file
		{
			*line = store;
			if (store)
				free(store);
        	return (0);
		}
	}
	printf("nl_index: %d\n", nl_index);
//  nl_index = new_line_index(store);
    if (nl_index >= 0)
    {
        store[nl_index] = '\0';
        *line = ft_strdup(store);
        temp = ft_strdup(store + nl_index + 1);
        if (store)
            free(store);
        store = temp;
        return (1);
    }
    return (0);
}
