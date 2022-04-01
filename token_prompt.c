#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
/**
*main - take the input command of the user
*Return: 0
*/

int main(void)
{
	int bytes_read, i = 0;
	size_t size;
	char *line_read;
	/*tokenizado*/
	char * token; 
	char * argv[] = {NULL, NULL, NULL, NULL};
	/*execve cosas*/
	char * env = {NULL};

	printf("$ ");

	size = 0;
	line_read = NULL;
	bytes_read = getline(&line_read, &size, stdin);
	
	/*tokenizamos la linea leida*/
	/*token /line_read = strtok(line_read, "\n"); */
	/*token /token = strtok(line_read, " "); */

	if (bytes_read == -1)
	{
		puts("no se reconoce como entrada valida");
	}
	else
	{
		/*tokenizamos la linea leida*/
		line_read = strtok(line_read, "\n");
		token = strtok(line_read, " ");

		/*puts(line_read);*/

		while (token != NULL || i < 3)
        	{
        	        printf("%s\n", line_read);
			argv[i] = token; 
			token = strtok(NULL, " ");
			i++;
		}

		/*process of execution order*/
		if ((execve(argv[0], argv, &env) == -1))
		{
			perror("Comando no encontrado\n");
		}


		free(line_read);
	}

	return (0);
}
