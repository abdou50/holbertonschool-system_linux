#include "multithreading.h"
#include <stdarg.h>

static pthread_mutex_t lock;
void init_mutex(void) __attribute__((constructor));
void destroy_mutex(void) __attribute__((destructor));

/**
 * init_mutex-initalis
 * Return: EXIT_SUCCESS
 */
void init_mutex(void)
{
	if (pthread_mutex_init(&lock, NULL))
	{
		printf("init mutex failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * destroy_mutex-destroy and go
 * Return: EXIT_SUCCESS
 */
void destroy_mutex(void)
{

	if (pthread_mutex_destroy(&lock))
	{
		printf("destroy mutex failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * tprintf-printf
 *@format: the format
 * Return: EXIT_SUCCESS
 */
int tprintf(char const *format, ...)
{
	va_list arg;

	va_start(arg, format);

	if (pthread_mutex_lock(&lock))
	{
		printf("lock failed\n");
		exit(EXIT_FAILURE);
	}

	printf("[%lu] ", pthread_self());
	vprintf(format, arg);
	pthread_mutex_unlock(&lock);
	va_end(arg);
	return (EXIT_SUCCESS);
}
