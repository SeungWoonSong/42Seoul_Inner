#include "inc/ft_printf.h"

int main()
{
	char temp[10] = "helloworld";
	ft_printf("123 %c 123\n",'d');
	printf("123 %c 123\n",'d');
	ft_printf("123%s444\n","helloworld");
	printf("123%s444\n","helloworld");
	ft_printf("123 %p 123\n",99999);
	printf("123 %p 123\n",99999);
	ft_printf("123 %d 123\n",0);
	printf("123 %d 123\n",0);
	ft_printf("123 %d 123\n",777);
	printf("123 %d 123\n",777);
	ft_printf("123 %i 123\n",777);
	printf("123 %i 123\n",777);
	ft_printf("123 %u 123\n",777);
	printf("123 %u 123\n",777);
	ft_printf("123 %x 123\n",81);
	printf("123 %x 123\n",81);
	ft_printf("123 %X 123\n",81);
	printf("123 %X 123\n",81);
	ft_printf("1. %s 2. %c 3. %d\n",temp,'a',123);
	printf("1. %s 2. %c 3. %d\n",temp,'a',123);

}


void j(void)
{

}
