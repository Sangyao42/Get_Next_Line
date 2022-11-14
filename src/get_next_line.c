/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:45:39 by sawang            #+#    #+#             */
/*   Updated: 2022/11/14 17:41:42 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*offset_str;

	line = get_one_line(fd, offset_str);

	return (line);
}

/**
*/
char	*get_one_line(int fd, char *offset_str)
{
	char	*first_line;
	int		offset;

	offset_str = (char *)malloc(1 * sizeof(char));
	first_line = (char *)malloc(1 * sizeof(char));
	while (offset_str)
	{
		offset_str = ft_strjoin(offset_str, read_file(fd, BUFFER_SIZE));
		offset = ft_strchr(offset_str, '\n');
		if (offset)
		{
			first_line = ft_substr(offset_str, 0, offset);
			offset_str = offset_str + ft_strlen(first_line);
			return (first_line);
		}
		else
			first_line = ft_strjoin(first_line, offset_str);
	}
	return (NULL);
}

char	*read_file(int fd, int count)
{
	char	*buffer;

	buffer = malloc(count);
	read(fd, buffer, count);
	return (buffer);
}
