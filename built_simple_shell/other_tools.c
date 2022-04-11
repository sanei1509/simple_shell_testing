#include "main.h"

/**
*getpadre_id - get the number id of process father
*Return: id number
*/

int getpadre_id(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	return (my_ppid);
}

/**
*gethijo_id - get the number id  of process hijo
*Return: id number
*/

int gethijo_id(void)
{
	pid_t my_pid;

	my_pid = getpid();
	return (my_pid);
}


/**
*ctrl_c - ignore the signal CTRL + C
*@signal: receive the signal
*/

void ctrl_c(int signal)
{
	if (signal == SIGINT)
		write(1, "\n$ ", 3);
}
