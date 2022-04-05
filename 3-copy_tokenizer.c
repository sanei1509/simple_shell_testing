#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/*
void clean_all(char *line_read, char **argv)
{
	free(line_read);
	line_read = NULL;
	free(argv);
}
*/

int count_spaces(char *line_read_copy)
{
	int s = 0;
	char *token_aux;

	token_aux = strtok(line_read_copy, " ");

	while (token_aux != NULL)
	{
		token_aux = strtok(NULL, " ");
		s++;
	}

	return (s);
}

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

/**
*main - take the input command of the user
*Return: 0
*/

int main(void)
{
	int bytes_read, i = 0, count_tokens = 0;
	size_t size;
	char *line_read, *token;
	char **argv = malloc(count_tokens * sizeof(char *));
	/*execve cosas*/
	char *env = {NULL};

	pid_t forkResultado;

	while (1)
	{
		i = 0;
		printf("#cisfun$");

		/*size = TAM_MAX; */
		/*line_read = (char *) malloc (size + 1);*/
		bytes_read = getline(&line_read, &size, stdin);

		if (bytes_read == -1)
		
			free(line_read);		
			puts("no se reconoce como entrada valida");
			return (1);
		}
		else
		{
			/*tokenizamos la linea leida*/
			line_read = strtok(line_read, "\n");
			token = strtok(line_read, " ");

		/*puts(line_read);*/
			while (token != NULL)
			{
				argv[i] = token;
				token = strtok(NULL, " ");
				i++;
				
				if(!argv)
				{
					exit(EXIT_FAILURE);
					printf("No se pasan argumentos");
				}
				free(line_read);
				line_read = NULL;
			}
			count_tokens = i + 1;
			printf("%d\n", count_tokens);
			if (strcmp(argv[0], "exit") == 0)
			{
				break;
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
	free(argv);
	}
	return (0);
}
