#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAM_MAX 10

int get_padre_id(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}

int get_hijo_id(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}

#define TAM_MAX 10
/**
*main - take the input command of the user
*Return: 0
*/

int main(void)
{
	char *salida = "exit";
	int bytes_read, i;
	size_t size;
	char *line_read, *token;
	/*char *argv[50] = {NULL};*/
	char *argv[50] = {NULL};
	/*execve cosas*/
	char *env = {NULL};
	pid_t forkResultado;

	while (1)
	{
		s 
		i = 0;
		printf("#cisfun$");

		/*size = 0;*/
		/*line_read = NULL;*/
		size = TAM_MAX;
		line_read = (char *) malloc (size + 1);
		
		if(line_read == NULL)
		{	
			free(line_read);
			exit(0);
		}
		bytes_read = getline(&line_read, &size, stdin);

	/*tokenizamos la linea leida*/
	/*token /line_read = strtok(line_read, "\n"); */
	/*token /token = strtok(line_read, " "); */

		if (bytes_read == -1)
		{
			puts("no se reconoce como entrada valida");
			exit (0);
		}
		else
		{
		/*tokenizamos la linea leida*/
			line_read = strtok(line_read, "\n");
			token = strtok(line_read, " ");
			
			if(token == salida)
				EOF;
		/*puts(line_read);*/
			while (token != NULL || i < 3)
			{
        		       /*printf("%s\n", line_read);*/
				argv[i] = token;
				token = strtok(NULL, " ");
				i++;
			}
				if (line_read != NULL)
				{
					forkResultado = fork();
						if (forkResultado == 0)
						{
							printf ("creando hijo..\n");
							get_padre_id();
							get_hijo_id();
							/*process of execution order*/
							if ((execve(argv[0], argv, &env) == -1))
							{
								perror("Comando no encontrado\n");
								exit(0);
							}
						}
						else
						{
							wait (NULL);
							continue;
						}
				}
				else
				{
					printf("Invalid Command\n");
				}
		}
	free(line_read);
	}
	return (0);
}
