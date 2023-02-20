#include <signal.h>
#include <sys/types.h>

/**
 * pid_exist - yake an id and check if it exists
 * @pid:  id to test
 *
 * Return: 1 if exists, 0
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
