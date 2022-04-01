#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*main - take the input command of the user
*Return: 0
*/

int main(void)
{
	int bytes_read;
	size_t size;
	char *line_read;
	/*tokenizado*/
	char *token;
	
	printf("$ ");

	size = 0;
	line_read = NULL;
	bytes_read = getline(&line_read, &size, stdin);
	
	/*tokenizamos la linea leida*/
	token = strtok(line_read, " "); 

	if (bytes_read == -1)
	{
		puts("no se reconoce como entrada valida");
	}
	else
	{
		puts(line_read);
		while (token != NULL)
        	{
        	        printf("%s\n", token);
        	        token = strtok(NULL, " ");
		}
		free(line_read);
	}

	return (0);
}
