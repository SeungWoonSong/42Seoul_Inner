#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

void maketrash(char *string)
{
	string = (char *)malloc(sizeof(char) * 100);
}

int main()
{
	int fd;
	char result[31];
	result[30] = 0;
	static char *test;
	int line;

	test = 1;
	// for (int i; i < 20; i++)
	// 	maketrash(test);
	// printf("%d\n", sizeof(test));
	// if (!test)
	// 	printf(" 없음");
	// else
	// 	printf("123123");
	fd = 0;
	fd = open("test.txt", O_RDONLY);
	while (test != '\0')
	{

		line = read(fd, result, 30);

		if (line == 0)
			break;
		result[line] = '\0';
		printf("%s", result);
	}
	// printf("%d\n\n", read(fd, result, 200));
	// printf("%d \n%s\n", fd, result);
}