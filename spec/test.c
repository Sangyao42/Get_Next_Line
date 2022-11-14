#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	// printf("%d\n", STDIN_FILENO);
	// int fd;
	// fd = STDIN_FILENO;
	// get_next_line(fd);
	// return (0);
	// printf("%zd\n", write(1, "abcde", 0));
	int	fd;
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
}

