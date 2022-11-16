/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:45:39 by sawang            #+#    #+#             */
/*   Updated: 2022/11/16 20:15:30 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*offset_str;

	offset_str = (char *)malloc(1);
	printf("address of offset_str when initialized: %p\n", &offset_str);
	line = get_one_line(fd, &offset_str);
	printf("add of line: %p\n", line);

	// printf("BUFFER SIZE : %i\n", BUFFER_SIZE);
	// printf("REST : %sEND\n", offset_str);
	// printf("RESULT : %s\n", line);
	free(offset_str - ft_strlen(line));
	return (line);
}

/**
*/
char	*get_one_line(int fd, char **offset_str)
{
	char	*first_line;
	size_t	offset;

	// first_line = malloc(1);
	while (*offset_str)
	{
		printf("2offset str in the while loop: %sEND\n", *offset_str);
		*offset_str = ft_strjoin(*offset_str, read_file(fd, BUFFER_SIZE));
		printf("address of offset_str when joined: %p\n", offset_str);
		printf("offset str in the while loop: %sEND\n", *offset_str);
		offset = ft_strchr(*offset_str, '\n');
		printf("offset equals to %zu\n", offset);
		if (offset > 0)
		{
			first_line = ft_substr(*offset_str, 0, offset);
			printf("add of first_line: %p\n", first_line);
			*offset_str = *offset_str + ft_strlen(first_line);
			printf("address of offset_str after cutting: %p\n", offset_str);
			// *offset_str = ft_strdup(*offset_str + ft_strlen(first_line));
			printf("if there is nl, the offset_str is: %sEND\n", *offset_str);
		}
		else
		{
			first_line = ft_strdup(*offset_str);
			// *offset_str = *offset_str + ft_strlen(first_line);
			printf("first line without nl %sEND\n", first_line);
		}
	}
	return (first_line);
}

char	*read_file(int fd, size_t count)
{
	char	*buffer;
	size_t	bytes_read;

	buffer = malloc(count + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, count);
	//malloc  not freed, causing rewriting problems?
	// printf("Check read buffer %s\n", buffer);
	if (bytes_read < count)
	{
		buffer[bytes_read] = '\0';
	}
	buffer[count] = '\0';
	return (buffer);
}

