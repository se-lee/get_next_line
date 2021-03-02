/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selee <selee@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:47:22 by selee             #+#    #+#             */
/*   Updated: 2021/03/02 15:26:56 by selee            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

//# ifndef BUFFER_SIZE
//#  define BUFFER_SIZE 32
//# endif

int			get_next_line(int fd, char **line);

size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
size_t		ft_strlcpy(char *restrict dst,
						const char *restrict src, size_t destsize);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_calloc(size_t count, size_t size);

#endif
