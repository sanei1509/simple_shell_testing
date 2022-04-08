#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

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

int count_spaces(char *aux_line)
{
	int i, cont = 0;

	for (i = 0; aux_line[i] != '\0'; i++)
	{
		if (aux_line[i] == ':')
		cont ++;
	}
	return(cont + 1); 
}


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
	printf("%u\n", my_ppid);
	return (0);
}

int gethijo_id(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}


char *_getenv(char *var, char **environ)
{	
	unsigned int i = 0;
	unsigned int len = _strlen(var);
	
	if (!environ || ! *var || strchr(var,'='))
		return (NULL);
	else
	while (environ[i] && (environ[i][len] != '=' || strncmp(var, environ[i], len)))
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
	sizepath = count_spaces(path);
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

char* compare_path(char **array, char *cmd)
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

	return (NULL);

}

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **env)
{
	int bytes_read = 0, i = 0, count_tokens = 0;
	size_t size = 0;
	char *line_read = NULL, *token = NULL, *env_t = {NULL};
	char **argv = NULL;
       	char **arr_paths = NULL;

	pid_t forkResultado;
	
	arr_paths = create_aux(arr_paths, env);

	while (1)
	{
		i = 0;
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
			/*Parseamos o limpiamos la entrada para su uso*/
			line_read = strtok(line_read, "\n");
			count_tokens = count_espacios(line_read);

			argv = calloc(count_tokens + 1, sizeof(char *));

			token = strtok(line_read, " ");

			while (token != NULL)
			{
				argv[i] = token;
				token = strtok(NULL, " ");
				i++;
			}
			
			if (line_read != NULL )
			{
				if ((strcmp(argv[0], "exit") == 0) || (strcmp(argv[0], "EOF") == 0))
					break, free(argv), free(line_read);

				if ((compare_path(arr_paths, argv[0])) == NULL)
				{
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
				continue;
			}
		}
		free(line_read);
		line_read = NULL;
		free(argv);
	}
	free(line_read);
	line_read = NULL;
	free(argv);
	return (0);
}
