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
	int bytes_read, i = 0, count_tokens = 0;
	size_t size = 0;
	char *line_read = NULL, *token = NULL, *env = {NULL};
	char **argv = NULL;

	pid_t forkResultado;

	while (1)
	{
		i = 0;

		printf("#cisfun$");

		/*devuelve el numero de caracteres leídos sin contar el '\0' */
		bytes_read = getline(&line_read, &size, stdin);

		if (bytes_read == -1)
		{
			puts("no se reconoce como entrada valida");
			continue;
		}
		else
		{
			/*Parseamos o limpeamos el string leído para poder usarlo*/
			line_read = strtok(line_read, "\n");
			token = strtok(line_read, " ");

			while (token != NULL && i < count_tokens)
			{
				argv[i] = token;
				token = strtok(NULL, " ");
				i++;
			}
			/**/
			if (line_read != NULL)
			{
				if (strcmp(argv[0], "exit") == 0)
					break;
				forkResultado = fork();
				if (forkResultado == 0)
				{
					printf ("creando hijo..\n");
					get_padre_id(), get_hijo_id();
					/*process of execution order*/
					if ((execve(argv[0], argv, &env) == -1))
					{
						free(line_read);
						free(argv);
						perror("Comando no encontrado\n");
						exit(0);
					}
				}
				else
				{
					wait (NULL);
				}
				free(line_read);
			}
			else
			{
				/*no recibimos entrada*/
				continue;
			}
		}
		free(line_read);
		line_read = NULL;
		free(argv);
	}
	free(line_read);
	free(argv);
	return (0);
}
