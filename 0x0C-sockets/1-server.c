#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

/**
 * main - main
 * Return: 1 or 0
 */
int main(void)
{
	int sick, NEW;
	struct sockaddr_in my_addr, their_addr;
	socklen_t sin_size;

	sick = socket(AF_INET, SOCK_STREAM, 0);
	if (sick == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(12345);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	memset(&(my_addr.sin_zero), '\0', 8);
	if (bind(sick, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1)
	{
		perror("bind");
		close(sick);
		exit(EXIT_FAILURE);
	}
	if (listen(sick, 10) == -1)
	{
		perror("listen");
		close(sick);
		exit(EXIT_FAILURE);
	}
	printf("Server listening on port 12345\n");
	sin_size = sizeof(their_addr);
	NEW = accept(sick, (struct sockaddr *)&their_addr, &sin_size);
	if (NEW == -1)
	{
		perror("accept");
		close(sick);
		exit(EXIT_FAILURE);
	}
	printf("Client connected: %s\n", inet_ntoa(their_addr.sin_addr));
	close(NEW);
	close(sick);
	return (0);
}
