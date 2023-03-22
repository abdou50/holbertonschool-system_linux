#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - impliment the readelf
 * @argc: count of args
 * @argv: args  passed to program
 * @env:  the environment
 * Return: 1 or 0
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	char *command[] = {"./hnm", "-p", "", NULL};

	command[2] = argv[1];
	if (execve("/usr/bin/nm", command, env) == -1)
	{
		perror("execv");
		return (0);
	}
	return (1);
}