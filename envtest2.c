#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *_strcat(char *dest, char *src)
{
	char *init = NULL;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	init = dest;
	while (*init != '\0')
		init++;
	while(*src != '\0')
		*init++ = *src++;
	*init = '\0';
	return (dest);
}

char *validate (char **str, char *line, int size)
{
	int i = 0;
	char *concatenacion;

	while (i < size)
	{
		concatenacion = strcat(str[i], line);
		printf("%s\n", concatenacion);
		i++;
	}
	return (concatenacion);
}

int main () 
{	
	char *prueba = "/ls", *concatenated = NULL;
	int j = 0, c = 0;
	char **aux = NULL;
	int cont = 0, sizepath = 0;
	char *path = NULL;
	char *tokenized = NULL;
	path = getenv("PATH");
	sizepath = count_spaces(path);
	aux = malloc(sizeof(char *) * sizepath);
	tokenized = strtok(path, ":");

	while (tokenized != NULL && cont < sizepath)
	{
		aux[cont] = tokenized;
		cont++;
		tokenized= strtok(NULL, ":");
	}

	while (j < sizepath)
	{
		printf("Soy el aux: %s\n", aux[j]);
		j++;
	}
	concatenated = _strcat(aux[1], prueba);
	/*printf("%s\n",aux[0]);*/
	
	for (c = 0; c < sizepath; c++)
	{
		printf("no se q:%s\n", aux[c]);
	}
	printf("%d\n", sizepath);
	free(aux);
	printf("%s\n", concatenated);
		return(0);
}
