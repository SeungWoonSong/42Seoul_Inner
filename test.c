#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void increas(int k)
{
	static int	apple;

	apple++;
	printf("apple is %d\n",apple);

}

void drcreas(int k)
{
	static int apple;
	apple++;

	printf("banana is %d", apple);
}

int	main()
{
	static int j;

	do
	{
		increas(j);
		drcreas(j);
		j++;
	} while (j < 10);

}
