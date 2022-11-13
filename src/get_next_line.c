/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:45:39 by sawang            #+#    #+#             */
/*   Updated: 2022/11/13 14:35:26 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char		*line;
	static char	*offset_str;

	line = get_one_line(offset_str);
	return (line);
}

/**
 * @var buffer
*/
char	*get_one_line(char *offset_str)
{
	char	*first_line;
	char	*buffer;
	// buffer for all buffer red by read????
	// char	*file_already_red;

	//?	file_already_red = malloc();
	buffer = read_file(fd, BUFFER_SIZE);
	int	 count= ft_strchr(offset_str,'\n');
	first_line = ft_substr(offset_str, 0, count);
	*offset_str = *offset_str + count;

	return (first_line);
}

char	*read_file(int fd, int count)
{
	char	*buffer;

	buffer = malloc(count + 1);
	read(fd, buffer, count);
	return (buffer);
}

