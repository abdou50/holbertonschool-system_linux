#include "signals.h"
/**
 * handler - function
 * @numsig: signal number
 * @info: signal information
 * @pointer: pointer of the information pid
 */
void handler(int numsig, siginfo_t *info, void *pointer)
{
	(void) numsig;
	(void) pointer;
	if (info)
	{
		printf("SIGQUIT send bu %i\n", info->si_pid);
		fflush(stdout);
	}
}
/**
 * trace_signal_sender - pid of the signal
 * Return: 1 or 0
 */
int trace_signal_sender(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;

	return (sigaction(SIGQUIT, &sa, NULL));
}
