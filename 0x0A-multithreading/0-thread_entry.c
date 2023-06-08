#include "multithreading.h"
#include <stdio.h>
/**
 * thread_entry - the entry point
 * @arg: the arguments
 * Return: 1 or 0
 */
void *thread_entry(void *arg)
{
	char *str;

	str = (char *)arg;
	printf("%s\n", str);
	pthread_exit(NULL);
}
