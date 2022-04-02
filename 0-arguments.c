#include <stdio.h>
#include <stdlib.h>

/**
 *main - program that prints all the arguments without ac
 *@ac: arguments count
 *@av: arguments vector or array
 *Return - 0
 */

void main(int __attribute__((unused)) ac, char **av)
{
	int i = 1;

	while (av[i] != NULL)
	{
		printf("arg -> %s\n", av[i]);
		i++;
	}
}
