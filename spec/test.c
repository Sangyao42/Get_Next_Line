#include "get_next_line_bonus.h"
#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

#include "stdlib.h"

// int	main(int argv, char **argc)
int main(void)
{
	// printf("%d\n", STDIN_FILENO);
	// int fd;
	// fd = STDIN_FILENO;
	// get_next_line(fd);
	// return (0);
	// printf("%zd\n", write(1, "abcde", 0));
	int		n;
	int		fd;
	char	*str;

	// if (argv < 0)
	// {
	// 	return (1);
	// }
	// fd = open(argc[1], O_RDONLY);
	fd = open("test.txt", O_RDONLY);
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

/**
 * Testing for bonus part
*/
	// int		fd_bonus1;
	// char	*str_bonus1;
	// int		fd_bonus2;
	// char	*str_bonus2;
	// fd_bonus1 = open("test.txt", O_RDONLY);
	// fd_bonus2 = open("test.txt", O_RDONLY);
	// n = 0;
	// printf("fd_bonus1: %d\n", fd_bonus1);
	// printf("fd_bonus2: %d\n", fd_bonus2);
	// str_bonus1 = get_next_line(fd_bonus1);
	// str_bonus2 = get_next_line(fd_bonus2);
	// while (str_bonus1)
	// {
	// 	printf("the %dth line from fd_bonus1 %d: %sFINAL\n", (n + 1),fd_bonus1, str_bonus1);
	// 	free(str_bonus1);
	// 	str_bonus1 = get_next_line(fd_bonus1);
	// 	n++;
	// }
	// n = 0;
	// while (str_bonus2)
	// {
	// 	printf("the %dth line from fd_bonus2 %d: %sFINAL\n", (n + 1),fd_bonus2, str_bonus2);
	// 	free(str_bonus2);
	// 	str_bonus2 = get_next_line(fd_bonus2);
	// 	n++;
	// }

	// system("leaks test.o");
	// char	*ptr;

	// ptr = malloc(sizeof(char) * 10);
	// change(ptr);
	// printf("PTR = %s\n", ptr);
	return (0);
}

