/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:40:03 by sawang            #+#    #+#             */
/*   Updated: 2023/11/21 22:51:01 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
// #include "strings.h"

/**
 * @brief read the files into buffer and
 * join the previous offset_str with buffer, if there is no '\n' in offset_str
 * @details If read() fails, offset_str and buffer should both be freed.
 * If read() returns 0, which means no more bytes is red,
 * buffer will not be changed, then break the loop.
 * and keep offset_str as how it was before.
 * Set buffer[red] = '\0' to set the buffer red as a string
 * for using ft_strjoin().
 * Once buffer is joined to offset_str, buffer should be freed
 * and the offset_str should be freed as well,
 * which is accomplished in ft_strjoin() using free(s1).
*/
static char	*read_and_accumulate(int fd, char *offset_str)
{
	char	*buffer;
	char	*accum_line;
	int		red;

	accum_line = ft_strdup(offset_str);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(accum_line), NULL);
	while (ft_strchr(accum_line, '\n') == 0)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
		{
			free(accum_line);
			accum_line = NULL;
			return (free (buffer), NULL);
		}
		if (red == 0)
			break ;
		buffer[red] = '\0';
		accum_line = ft_strjoin(accum_line, buffer);
	}
	free (buffer);
	return (accum_line);
}

/**
 * @brief Return the first line seperated by '\n' from offset_str.
 * @details If there is no '\n' in offset_str, return the value of offset_str,
 * which means it returns the last line of the file without a newline.
*/
static char	*get_first_line(char *accum_line)
{
	char	*line;
	size_t	len;

	if (!accum_line)
		return (NULL);
	len = ft_strchr(accum_line, '\n');
	if (len)
	{
		line = (char *)malloc(sizeof(char) * (len + 1));
		if (!line)
			return (NULL);
		line[len] = '\0';
		line = ft_memcpy(line, accum_line, len);
	}
	else
		line = ft_strdup(accum_line);
	return (line);
}

/**
 * @brief Store the string behind the '\n'
 * @details If there is '\n' in offset_str, using ft_strdup() make a copy of
 * the string starting from (offset_str + len) and free the previous offset_str
 * using a pointer (first set a ptr points to previous offset_str,
 * after ft_strdup(), free the ptr, which frees the previous offset_str).
 * If there is no '\n' in offset_str, which means we reach the last line of
 * the file, thus offset_str should be freed and
 * make offset_str points to nowhere when finishing reading.
*/
static void	get_offset_str(char *accum_line, char *offset_str)
{
	size_t	len;
	int		i;

	if (!accum_line)
		offset_str[0] = '\0';
	len = ft_strchr(accum_line, '\n');
	if (len)
	{
		i = 0;
		while (i <= BUFFER_SIZE)
		{
			offset_str[i] = '\0';
			i++;
		}
		offset_str = ft_memcpy(offset_str, accum_line + len, \
			ft_strlen(accum_line + len));
	}
	else
		offset_str[0] = '\0';
}

char	*get_next_line(int fd)
{
	char		*accum_line;
	char		*line;
	static char	offset_str[BUFFER_SIZE + 1] = {0};

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	accum_line = read_and_accumulate(fd, offset_str);
	line = get_first_line(accum_line);
	get_offset_str(accum_line, offset_str);
	// printf("tests: offset_str: %s\n", offset_str);
	free(accum_line);
	accum_line = NULL;
	return (line);
}
