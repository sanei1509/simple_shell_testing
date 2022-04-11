#include "main.h"

/**
*count_spaces - count
*
*/

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

/**
**getenv . return the full content of environmennts var PATH
*@var : string of the name of variable that we want get
*@environ : list with the environments data
*Return: NULL or the complete environment
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


char **return_env(char **environ)
{
	char **s = environ;

	for (; *s; s++) 
	{
		printf("%s\n", *s);
	}

	return 0;
}


/**
***create_aux - take a empty array to fill with the paths
*@aux1 : empty array from main function
*@env_aux : complete list of environments
*Return: 0
*/

char **create_aux(char **aux1, char **env_aux)
{
	char *tokenized = NULL, *var = "PATH", *path = NULL;
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
