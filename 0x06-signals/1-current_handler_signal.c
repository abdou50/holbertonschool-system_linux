#include "signals.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
/**
 * current_handler_signal - recive the signel
 * Return: the current signal
 */
void (*current_handler_signal(void))(int)
{
	void (*current)(int) = NULL;

	current = signal(SIGINT, NULL);
	signal(SIGINT, current);
	return (current);
}
