#include "signals.h"
/**
 * main - sets a handler for the signal SIGINT
 * @argc: argument count
 * @argv: argument value
 * Return: EXIT_SUCCESS otherwise 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	printf("%s: %s\n", argv[1], strsignal(atoi(argv[1])));
	return (1);

}

