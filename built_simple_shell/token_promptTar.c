#include "main.h"

extern char **environ;

void clean_everything(char * line, char ** array)
{
	free(line);
	line = NULL;
	free(array);
}

/*deberíamos pasarle una copia del string*/
int count_espacios(char *aux_line)
{
	int s = 0;
	char *aux, *copy_line = strdup(aux_line);

	aux = strtok(copy_line, " ");

	while (aux != NULL)
	{
		s++;
		aux = strtok(NULL, " ");
	}

	return (s);
}

int getpadre_id(void)
{
	pid_t my_ppid;
	my_ppid = getppid();
	return (my_ppid);
}

int gethijo_id(void)
{
	pid_t my_pid;

	my_pid = getpid();
	return (my_pid);
}

/*funciones para estructurar*/
char** parser_line(char **array, char * line)
{
	int count_tokens = 0, i = 0;
	char *token = NULL;

	line = strtok(line, "\n");
	count_tokens = count_espacios(line);
	array = calloc(count_tokens + 1, sizeof(char *));
	token = strtok(line, " ");

	while (token != NULL)
	{
		array[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	return (array);
}

/**
*main - take the input command of the user
*Return: 0
*/

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **env)
{
	int bytes_read = 0;
	size_t size = 0;
	char *line_read = NULL;
	char **argv = NULL;
       	char **arr_paths = NULL;
	char *ret_pathcmd;

	pid_t forkResultado;
	arr_paths = create_aux(arr_paths, env);

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);

		bytes_read = getline(&line_read, &size, stdin);

		if (line_read[0] == '\n')
			continue;
		if (bytes_read == -1 || line_read[0] == EOF)
		{
			perror("Error");
			break;
		}
		else
		{
			/*Parseamos o limpiamos y contamos los tokens para alojar memoria*/
			argv = parser_line(argv, line_read);			
			/*cargo variable con el retorno de compararar rutas con stat*/
			ret_pathcmd = compare_path(arr_paths, argv[0]);
			if (line_read != NULL )
			{
				if(line_read[0] == ' ' )
					continue;
				if ((_strcmp(argv[0], "exit") == 0) || (_strcmp(argv[0], "EOF") == 0))
					break;
				if (ret_pathcmd == NULL)
				{
					perror("Error");
					continue;
				}
				if (_strcmp(argv[0], "env") == 0)
				{
					return_env(environ);
					continue;
				}
			/*reasignación del comando paraentender que le mandamos*/
				argv[0] = ret_pathcmd;
				forkResultado = fork();
				if (forkResultado == 0)
				{
					printf ("creando hijo..\n");
					getpadre_id(), gethijo_id();
					/*process of execution order*/
					if ((execve(argv[0], argv, env) == -1))
					{
						if(line_read[0] == ' ')
							continue;
						free(line_read);
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
				free(line_read);
				line_read = NULL;
				continue;
			}
			free(arr_paths);
		}
		clean_everything(line_read, argv);
	}
	clean_everything(line_read, argv);
	return (0);
}
