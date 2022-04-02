#include <stdio.h>
#include <stdlib.h>

/**
*main - take the input command of the user
*Return: 0
*/

int main(void)
{
	int bytes_read;
	size_t size;
	char *line_read;

	printf("$ ");

	size = 0;
	line_read = NULL;
	bytes_read = getline(&line_read, &size, stdin);

	if (bytes_read == -1)
	{
		puts("no se reconoce como entrada valida");
	}
	else
	{
		puts(line_read);
	}

	free(line_read);
	return (0);
}
