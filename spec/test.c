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
	char	*str;

	if (argv < 0)
	{
		return (1);
	}
	fd = open(argc[1], O_RDONLY);
	n = 0;
	printf("fd: %d\n", fd);
	str = get_next_line(fd);
	while (str)
	{
		printf("the %dth line: %sFINAL\n", (n + 1), str);
		free(str);
		str = get_next_line(fd);
		n++;
	}
	system("leaks test.o");
	// char	*ptr;

	// ptr = malloc(sizeof(char) * 10);
	// change(ptr);
	// printf("PTR = %s\n", ptr);
	return (0);
}

