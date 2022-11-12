#include "../src/get_next_line.h"
#include <stdio.h>

int	main(void)
{
	// printf("%d\n", STDIN_FILENO);
	// int fd;
	// fd = STDIN_FILENO;
	// get_next_line(fd);
	// return (0);
	printf("%zd\n", write(1, "abcde", 0));
}

