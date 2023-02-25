#include "signals.h"
/**
 * handler_sig - handler
 * @numsig: numsignal
 */
void handler_sig(int numsig)
{
	printf("Caught %d\n", numsig);
}
/**
 * main - sets a handler for the signal SIGINT
 * Return: EXIT_SUCCESS otherwise 0
 */
int main(void)
{
	struct sigaction sa;

	sa.sa_handler = &handler_sig;
	sigaction(SIGINT, &sa, NULL);
	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
