#include <stdio.h>
#include <stdlib.h>

int main(int __attribute__((unused)) ac, char **av)
{
	int i = 1;

	while(av[i] != NULL)
	{
		printf("arg -> %s\n", av[i]);
		i++;
	}
}
