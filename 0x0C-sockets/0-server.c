#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>

/**
 * main - main
 * Return: 1 or 0
 */

int main(void)
{
	struct sockaddr_in addrport;
	int socketid;

	socketid = socket(AF_INET, SOCK_STREAM, 0);
	if (socketid < 0)
	{
		perror("socket failed");
		return (EXIT_FAILURE);
	}
	addrport.sin_family = AF_INET;
	addrport.sin_port = htons(12345);
	addrport.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(socketid, (struct sockaddr *)&addrport, sizeof(addrport)) < 0)
	{
		perror("bind failed");
		return (EXIT_FAILURE);
	}
	if (listen(socketid, 10) < 0)
	{
		perror("listen failed");
		return (EXIT_FAILURE);
	}
	printf("Server listening on port 12345\n");
	while (1 == 1)
		;
	return (EXIT_SUCCESS);
}
