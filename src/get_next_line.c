/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:22:07 by sawang            #+#    #+#             */
/*   Updated: 2022/11/17 22:41:24 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read(int fd, ssize_t count)
{
	char		*buffer;
	ssize_t		readed;

	buffer = (char *)malloc(sizeof(char) * (count + 1));
	if (!buffer)
		return (NULL);
	readed = read(fd, buffer, count);
	if (buffer && readed < 0)
		*buffer = '\0';
	else if (readed < count)
		*(buffer + readed) = 0;
	*(buffer + count) = 0;
	return (buffer);
}

char	*read_and_accumulate(char *offset_str, int fd)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(offset_str, '\n') == 0)
	{
		buffer = ft_read(fd, BUFFER_SIZE);
		if (!*buffer)
			return (NULL);
		offset_str = ft_strjoin(offset_str, buffer);
	}
	free(buffer);
	return (offset_str);
}

char	*get_first_line(char *offset_str)
{
	char	*line;
	size_t	len;

	if (!offset_str)
		return (NULL);
	len = ft_strchr(offset_str, '\n');
	if (len)
		line = ft_substr(offset_str, 0, len);
	else
		line = ft_strdup(offset_str);
	return (line);
}

char	*get_offset_str(char *offset_str)
{
	size_t	len;

	if (!offset_str)
		return (NULL);
	len = ft_strchr(offset_str, '\n');
	if (len)
		offset_str = ft_strdup(offset_str + len);
	// else
	// 	line = ft_strdup(offset_str);
	return (offset_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*offset_str;

	// // offset_str = (char *)malloc(1);
	// printf("address of offset_str when initialized: %p\n", &offset_str);
	// line = get_one_line(fd, &offset_str);
	// printf("add of line: %p\n", line);

	// // printf("BUFFER SIZE : %i\n", BUFFER_SIZE);
	// // printf("REST : %sEND\n", offset_str);
	// // printf("RESULT : %s\n", line);
	// free(offset_str - ft_strlen(line));
	// return (line);
	offset_str = read_and_accumulate(offset_str, fd);
	line = get_first_line(offset_str);
	offset_str = get_offset_str(offset_str);

	return (line);
}
