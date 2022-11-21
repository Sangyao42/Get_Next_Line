/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:22:07 by sawang            #+#    #+#             */
/*   Updated: 2022/11/21 22:57:23 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// char	*ft_read(int fd, ssize_t count)
// {
// 	char		*buffer;
// 	ssize_t		readed;

// 	buffer = (char *)malloc(sizeof(char) * (count + 1));
// 	if (!buffer)
// 		return (NULL);
// 	readed = read(fd, buffer, count);
// 	if (readed == -1)
// 	{
// 		free(buffer);
// 		buffer = NULL;
// 	}
// 	else if (readed < count)
// 	{
// 		*(buffer + readed) = 0;
// 		printf("a buffertest:%sENDA\n", buffer);
// 	}

// 	*(buffer + count) = 0;
// 	printf("b bufferstest:%sENDB\n", buffer);
// 	return (buffer);
// }

// char	*read_and_accumulate(char *offset_str, int fd)
// {
// 	char	*buffer;

// 	// buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));

// 	while (ft_strchr(offset_str, '\n') == 0)
// 	{
// 		buffer = ft_read(fd, BUFFER_SIZE);
// 		// if (!buffer)
// 		// 	return (NULL);
// 		if (*buffer && ft_strlen(buffer) <= BUFFER_SIZE)
// 			// offset_str =;//lose last line
// 			offset_str = ft_strjoin(offset_str, buffer);
// 		else
// 		{
// 			free (buffer);
// 			return (NULL);
// 		}
// 	}
// 	free(buffer);
// 	return (offset_str);
// }

// void	*clear(char *buf)
// {
// 	free(buf);
// 	return (NULL);
// }

// char	*read_and_accumulate(char *offset_str, int fd)
// {
// 	char	*buffer;
// 	int		readed;

// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (NULL);
// 	readed = read(fd, buffer, BUFFER_SIZE);
// 	if (readed)
// 		offset_str = ft_strjoin(offset_str, buffer);
// 	while (ft_strchr(offset_str, '\n') == 0 && readed)
// 	{
// 		if (readed == -1)
// 			return (clear(buffer));
// 		buffer[readed] = '\0';
// 		if (readed < BUFFER_SIZE)
// 			break ;
// 		if (!ft_strchr(offset_str, '\n'))
// 		{
// 			readed = read(fd, buffer, BUFFER_SIZE);
// 			if(readed)
// 				offset_str = ft_strjoin(offset_str, buffer);
// 		}
// 	}
// 	free(buffer);
// 	return (offset_str);
// }

// void	*buffer_free(void *buffer)
// {
// 	free(buffer);
// 	return (NULL);
// }

char	*read_and_accumulate(int fd, char *offset_str)
{
	char	*buffer;
	int		red;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(offset_str, '\n') == 0)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
			return (free (buffer), NULL);
		if (red == 0)
		{
			// printf("offset_str: %s\n", )
			break ;
		}
		buffer[red] = '\0';
		offset_str = ft_strjoin(offset_str, buffer);
		if (!offset_str)
			return (free (buffer), NULL);
	}
	free (buffer);
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
	{
		line = ft_substr(offset_str, 0, len);
		if (!line)
			return (NULL);
	}
	else
	{
		line = ft_strdup(offset_str);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_offset_str(char *offset_str)
{
	size_t	len;
	char	*ptr;

	if (!offset_str)
		return (NULL);
	len = ft_strchr(offset_str, '\n');
	if (len)
	{
		// printf("offset_str + len: %sEND\n", offset_str + len);
		ptr = offset_str;
		offset_str = ft_strdup(offset_str + len);
		free(ptr);
		if (!offset_str)
			return (NULL);
	}
	else
	{
		// if (offset_str)
		// {
			free(offset_str);
			return (NULL);
		// }
	}
	return (offset_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*offset_str;

	// printf("offset_str0: %s\n", offset_str);
	offset_str = read_and_accumulate(fd, offset_str);
	// printf("offset_str1: %s\n", offset_str);
	line = get_first_line(offset_str);
	// printf("offset_str2: %s\n", offset_str);
	offset_str = get_offset_str(offset_str);
	// printf("offset_str3: %s\n", offset_str);
	return (line);
}
