#include "../include/philo.h"

size_t time_ft()
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("%ld", current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int main()
{
	size_t i = time_ft();
}
