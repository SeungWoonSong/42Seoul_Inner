#include <stdio.h>
#include <unistd.h>


int main()
{
	while(1){
		write(1, "y", 1);
	}
}
