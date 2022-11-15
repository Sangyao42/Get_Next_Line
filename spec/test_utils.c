#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

int	main(void)
{
	/**
	 * testing return value of read()
	*/
	int		fd;
	char	*buffer;
	char	*buffer_for_size;
	int		ret_val_read_until_eof; //?return 0?
	// int		ret_val_count_zero;
	int		ret_val_buffer_size;

	fd = open("test.txt", O_RDONLY);
	printf("get %d buffersize from fileno %d\n", BUFFER_SIZE, fd);

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	buffer_for_size = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer || !buffer_for_size)
		return (-2);
	ret_val_read_until_eof = read(fd, buffer, BUFFER_SIZE);
	printf("%d\n", ret_val_read_until_eof);
	printf("%s at %p\n", buffer, buffer);
	/**
	 * if read() does not check for errors,
	 * a read() with a count of 0 returns zero and has no other effects
	*/
	// ret_val_count_zero = read(fd, buffer, 0);
	// printf("%d\n", ret_val_count_zero);
	// printf("%s\n", buffer);

	printf("buffersize is %d\n", BUFFER_SIZE);
	ret_val_buffer_size = read(fd, buffer_for_size, BUFFER_SIZE);
	printf("%d\n", ret_val_buffer_size);
	printf("%s at %p\n", buffer_for_size, buffer_for_size);

	free(buffer);
	return (0);
}
