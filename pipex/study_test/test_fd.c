#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **fd;

	fd = (int **)malloc(sizeof(int *) * 10);
	for(int i ; i < 10; i++)
		fd[i] = (int *)malloc(sizeof(int)  * 2);
	for(int i; i < 10; i++)
	{
		fd[i][i % 2] = 1;
	}
	for(int i; i < 10; i++)
	{
		printf("%d\n",fd[i][i % 2]);
	}

}
