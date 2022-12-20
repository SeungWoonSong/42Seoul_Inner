#include "../include/philo.h"

int main()
{
	pthread_mutex_t test;

	pthread_mutex_init(&test,NULL);
	pthread_mutex_lock(&test);
	printf("%d", test);
}
