#include "get_next_line.h"

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

int main()
{
	char a[10] = "helloworl";

	printf("%s", ft_strchr(a, 'w'));
}