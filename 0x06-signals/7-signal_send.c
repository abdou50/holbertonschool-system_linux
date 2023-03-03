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
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (kill(atoi(argv[1]), SIGINT) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
