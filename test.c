#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


void ft_printf(char *s, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, s);
	while(s[i])
	{
		if(s[i] != '%')
			write(1, &s[i], 1);
		else
		{
			write(1, va_arg(ap, char), 1);
			i++;
		}
		i++;

	}

}





int main()
{
	ft_printf("hello %c",'z');
}

