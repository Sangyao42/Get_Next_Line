#include "../src/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	/**
	 * testing return value of read()
	*/
	int		fd;
	char	*buffer;
	int		ret_val_read_until_EOF;
	int		ret_val_count_zero;

	fd = open("test.txt", O_RDONLY);
	buffer = (char *)malloc(100 * sizeof(char));
	if (!buffer)
		return (-2);
	ret_val_read_until_EOF = read(fd, buffer, 80);
	printf("%d\n", ret_val_read_until_EOF);
	ret_val_count_zero = read(fd, buffer, 0);
	printf("%d\n", ret_val_count_zero);
	printf("%s\n", buffer);
	free(buffer);
	return (0);
}
