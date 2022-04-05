#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/*
char search_path(int ac, char **av, char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
*/

/*deberíamos pasarle una copia del string*/
int count_spaces(char *aux_line)
{
	int s = 0;
	char *aux;
        
	aux = strtok(aux_line, " ");

	while (aux != NULL)
	{
		s++;
		aux = strtok(NULL, " ");
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
	int bytes_read = 0, i = 0;
	size_t size = 0;
	char *line_read = NULL, *token = NULL, *env = {NULL};
	char *argv[25] = {NULL};
        
	pid_t forkResultado;
	
	while (1)
	{
		i = 0;
		printf("#cisfun$");

		bytes_read = getline(&line_read, &size, stdin);

		if (bytes_read == -1)
		{
			free(line_read);
			perror("Error bytes read");
			break;
		}
		else
		{
		/*tokenizamos la linea leida*/
			/*aux_line = strdup(line_read); */
			line_read = strtok(line_read, "\n");
			token = strtok(line_read, " ");
			
			/*argv = calloc(25, sizeof(char *)); */
			/*count_tokens = count_spaces(aux_line);*/
			/*allocate memory then the counter*/
			/*argv = calloc(count_tokens + 1, sizeof(char *));*/

			while (token != NULL)
			{
				argv[i] = token;
				token = strtok(NULL, " ");
				i++;
			}

				if (line_read != NULL)
				{
					if (line_read[0] == '\n')
						continue;
					if (strcmp(argv[0], "exit") == 0)
						break;
					if (strcmp(argv[0], "EOF") == 0)
						break;
					forkResultado = fork();
						if (forkResultado == 0)
						{
							printf ("creando hijo..\n");
							get_padre_id();
							get_hijo_id();
							/*process of execution order*/
							if ((execve(argv[0], argv, &env) == -1))
							{
								free(line_read);
								perror("Comando no encontrado\n");
								exit(0);
							}
						}
						else
						{
							wait (NULL);
						}
				}
				else
				{
					free(line_read);
					line_read = NULL;
					continue;
				}
		}
	free(line_read);
	line_read = NULL;
	}
	free(line_read);
	line_read = NULL;
	return (0);
}
