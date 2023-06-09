#include "multithreading.h"

/**
 * tprintf-printf
 * @format: the format
 * Return: 1 or 0
 */
int tprintf(char const *format, ...)
{
	printf("[%lu] %s", pthread_self(), format);
	return (EXIT_SUCCESS);
}
