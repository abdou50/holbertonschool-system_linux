#include "signals.h"
/**
 * handler - Entry point
 *
 *@numsig: <signum> must be replaced with the signal number that was caught
 */
void handler(int numsig)
{
	printf("Gotcha! [%d]\n", numsig);
	fflush(stdout);
}
/**
 * handle_sigaction - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = &handler;
	return (sigaction(SIGINT, &sa, NULL));
}
