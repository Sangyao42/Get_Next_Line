#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>

#include "stdlib.h"

int	main(int argv, char **argc)
{
	// printf("%d\n", STDIN_FILENO);
	// int fd;
	// fd = STDIN_FILENO;
	// get_next_line(fd);
	// return (0);
	// printf("%zd\n", write(1, "abcde", 0));

	int	fd;
	if (argv < 0)
	{
		return (1);
	}
	fd = open(argc[1], O_RDONLY);
	printf("fd: %d\n", fd);
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("the final result%s", get_next_line(fd));
	// printf("the final result%s", get_next_line(fd));
	// printf("the final result%s", get_next_line(fd));
	// printf("the final result%s", get_next_line(fd));
	// printf("the final result%s", get_next_line(fd));
	// printf("the final result%s", get_next_line(fd));
	// printf("the final result%s", get_next_line(fd));
	// printf("the final result%s", get_next_line(fd));
	// printf("the final result%s", get_next_line(fd));


	// char	*ptr;

	// ptr = malloc(sizeof(char) * 10);
	// change(ptr);
	// printf("PTR = %s\n", ptr);
	return (0);
}

