#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int _strncmp(const char s1[], const char s2[], size_t n) {

	unsigned char c1 = '\0';
	unsigned char c2 = '\0';
	int i;

	for (i = 0; i < (int) n; i++) {

		c1 = (unsigned char) s1[i];
		c2 = (unsigned char) s2[i];

		if ((c1 == '\0') || (c1 != c2)) {

			return (c1 - c2);

		}

	}
	return (c1 - c2);
}


void clean_everything(char *line, char *array)
{
	free(line);
	line = NULL;
	free(array);
}

char *_strcat(char *dest, char *src)
{
        int dest_length = 0, src_length = 0, i = 0;
        char *new_string = NULL;

        while (dest[dest_length] != '\0')
                dest_length++;

        while (src[src_length] != '\0')
                src_length++;

        new_string = calloc(2, (dest_length + src_length + 1) * sizeof(char));

        while (dest_length > i)
        {
                new_string[i] = dest[i];
                i++;
        }

        i = 0;

        while (src_length > i)
        {
                new_string[dest_length + i] = src[i];
                i++;
        }

        new_string[dest_length + i + 1] = '\0';

        return (new_string);
}

int count_paths(char *aux_line)
{
	int i, cont = 0;

	for (i = 0; aux_line[i] != '\0'; i++)
	{
		if (aux_line[i] == ':')
		cont ++;
	}
	return (cont + 1);
}

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/*
strlen - swaps the value of two integers
* @s: The pointer value one
* Return: c
*/

int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
		c++;

	return (c);
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


/**
 **_getenv - return the full var PATH
 *@var - 
 */
char *_getenv(char *var, char **environ)
{	
	unsigned int i = 0;
	unsigned int len = _strlen(var);
	
	if (!environ || ! *var || strchr(var,'='))
		return (NULL);
	else
	while (environ[i] && (environ[i][len] != '=' || _strncmp(var, environ[i], len)))
		i++;

	return (environ[i]) ? (environ[i] + len + 1) : (NULL);
}


/**
*main - take the input command of the user
*Return: 0
*/

char **create_aux (char **aux1, char **env_aux)
{
	char *tokenized = NULL, *var = "PATH";
	char *path = NULL;
	int cont = 0, sizepath = 0;
	path = _getenv(var, env_aux);
	sizepath = count_paths(path);
	aux1 = malloc(sizeof(char *) * sizepath + 1);
	tokenized = strtok(path, ":");

	while (tokenized != NULL || cont < sizepath)
        {
                aux1[cont] = tokenized;
                cont++;
                tokenized= strtok(NULL, ":");
        }
	return (aux1);
}

char *compare_path(char **array, char *cmd)
{
	struct stat buf;
	char *str = _strcat("/", cmd), *path_cmd = NULL;
	int i = 0;

	for (i = 0; array[i]; i++)
	{
		path_cmd = _strcat(array[i], str);
		if (stat(path_cmd, &buf) == 0)
		{
			return (path_cmd);
		}
	}

	free(path_cmd);
	free(str);
	return (NULL);

}

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

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **env)
{
	int bytes_read = 0;
	size_t size = 0;
	char *line_read = NULL, *env_t = {NULL};
	char **argv = NULL;
       	char **arr_paths = NULL;

	pid_t forkResultado;

	arr_paths = create_aux(arr_paths, env);

	while (1)
	{
		printf("#cisfun$");

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

			if (line_read != NULL )
			{
				if ((_strcmp(argv[0], "exit") == 0) || (_strcmp(argv[0], "EOF") == 0))
				{
					free(line_read), free(arr_paths);
					break;
				}
				if ((compare_path(arr_paths, argv[0])) == NULL)
				{
					free(arr_paths);
					perror("Error");
					continue;
				}
			/*reasignación del comando paraentender que le mandamos*/
				argv[0] = compare_path(arr_paths, argv[0]);
				forkResultado = fork();
				if (forkResultado == 0)
				{
					printf ("creando hijo..\n");
					getpadre_id(), gethijo_id();
					/*process of execution order*/
					if ((execve(argv[0], argv, &env_t) == -1))
					{
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
				free(arr_paths);
				continue;
			}
			bytes_read = 0;
			free(line_read);
			line_read = NULL;
		}
		free(line_read);
		line_read = NULL;
		free(argv);
	}
	free(arr_paths);
	free(line_read);
	line_read = NULL;
	free(argv);
	return (0);
}
