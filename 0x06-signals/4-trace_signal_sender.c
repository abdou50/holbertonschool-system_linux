#include "signals.h"
void handler(int sig, siginfo_t *info, void *ucontext)
{
    (void) sig;
    (void) ucontext;
    if (info)
    {
        printf("SIGQUIT send bu %i\n", info->si_pid);
        fflush(stdout);
    }
}
int trace_signal_sender(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;

    return (sigaction(SIGQUIT, &sa, NULL));
}