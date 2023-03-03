#include "signals.h"
/**
 * handler - function
 * @sig: the signal
 * @info: info about the sig
 * @context: the context
 */
void handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	psiginfo(info, "Caught");
}
/**
 * all_in_one - that sets up a single handler for all the signals
 */
void all_in_one(void)
{
	struct sigaction sa;
	int sig;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	for (sig = 1; sig < SIGRTMAX; sig++)
		sigaction(sig, &sa, NULL);
}
