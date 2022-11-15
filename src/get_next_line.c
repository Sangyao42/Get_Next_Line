/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:45:39 by sawang            #+#    #+#             */
/*   Updated: 2022/11/15 19:04:37 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*offset_str;

	offset_str = (char *)malloc(1);
	line = get_one_line(fd, &offset_str);

	printf("BUFFER SIZE : %i\n", BUFFER_SIZE);
	printf("REST : %sEND\n", offset_str);
	printf("RESULT : %s\n", line);
	free(offset_str);
	return (line);
}

/**
*/
char	*get_one_line(int fd, char **offset_str)
{
	char	*first_line;
	int		offset;
	// char	*buffer;//only the buffer would give info to first-line?

	while (*offset_str)
	{
		*offset_str = ft_strjoin(*offset_str, read_file(fd, BUFFER_SIZE));
		offset = ft_strchr(*offset_str, '\n') + 1;
		if (offset >= 0)
		{
			first_line = ft_substr(*offset_str, 0, offset);
			*offset_str = *offset_str + ft_strlen(first_line);
			// printf("%s\n", offset_str);
			return (first_line);
		}
		else
		{
			first_line = ft_strjoin(first_line, *offset_str);
			// offset_str
		}
	}
	return (NULL);
}

char	*read_file(int fd, int count)
{
	char	*buffer;

	buffer = malloc(count + 1);
	if (!buffer)
		return (NULL);
	read(fd, buffer, count);
	return (buffer);
}

