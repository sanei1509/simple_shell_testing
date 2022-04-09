#include "main.h"

int getpadre_id(void)
{
	pid_t my_ppid;
	my_ppid = getppid();
	return (my_ppid);
}

int gethijo_id(void)
{
	pid_t my_pid;

	my_pid = getpid();
	return (my_pid);
}

void ctrl_c (int signal)
{
	if (signal == SIGINT)
		write(1, "\n$ ", 3);
}
