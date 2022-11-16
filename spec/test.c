#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>

#include "stdlib.h"

void	change(char *ptr)
{

	ptr[0] = 'A';
	ptr[1] = 'A';
	ptr[2] = '\0';
	// ptr = ft_substr("HELLOOOO", 0, 5);

}

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
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	printf("the final result: %sFINAL\n", get_next_line(fd));
	printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
	// printf("\n");
	// printf("the final result: %sFINAL\n", get_next_line(fd));
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

}

