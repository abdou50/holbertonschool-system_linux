#include "signals.h"
/**
 * handler - set a handler
 * @signal: signal
 */
void handler(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}

/**
 * handle_signal - set a handle
 * Return: 0 on success, -1 in failure
 */
int handle_signal(void)
{
	if (signal(SIGINT, handler) == SIG_ERR)
		return (-1);
	return (0);
}
