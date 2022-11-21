#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#include "stdlib.h"

int	main(int argv, char **argc)
{
	// printf("%d\n", STDIN_FILENO);
	// int fd;
	// fd = STDIN_FILENO;
	// get_next_line(fd);
	// return (0);
	// printf("%zd\n", write(1, "abcde", 0));
	int n;
	int	fd;

	if (argv < 0)
	{
		return (1);
	}
	fd = open(argc[1], O_RDONLY);
	n = 0;
	printf("fd: %d\n", fd);
	while (n < 3)
	{
		printf("the %dth line: %sFINAL\n", (n + 1), get_next_line(fd));
		n++;
	}

	// char	*ptr;

	// ptr = malloc(sizeof(char) * 10);
	// change(ptr);
	// printf("PTR = %s\n", ptr);
	return (0);
}

