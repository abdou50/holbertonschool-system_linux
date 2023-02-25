t#include "signals.h"
/**
 * current_handler_sigaction - recive the signel
 * Return: the current signal
 */
void (*current_handler_sigaction(void))(int){
	struct sigaction sa;

	if (sigaction(SIGINT, NULL, &sa) == -1)
		return (NULL);
	return (sa.sa_handler);
}
