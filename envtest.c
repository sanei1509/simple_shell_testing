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

/*i
{	
	char *concatenated = NULL;
	int j = 0, c = 0;
	char **aux = NULL;
	/iint cont = 0, sizepath = 0;
	char *path = NULL;
	char *tokenized = NULL;
	path = getenv("PATH");
	sizepath = count_spaces(path); */
/*ux = malloc(sizeof(char *) * sizepath);
	tokenized = strtok(path, ":"); */

/*hile (tokenized != NULL && cont < sizepath)
	{
		aux[cont] = tokenized;
		cont++;
		tokenized= strtok(NULL, ":");
	}

	while (j < sizepath)
	{
		printf("%s\n", aux[j]);
		j++;
	}
	concatenated = _strcat(aux[4], prueba);
	printf("%s\n",aux[0]);*/
	
/*or (c = 0; aux[c]; c++)
	{
		printf("%s\n", aux[c]);
	}
	printf("%d\n", sizepath);
	free(aux);
	printf("%s\n", concatenated);
		return(0);
} */

char **create_aux (char **aux1)
{
	char *tokenized = NULL; 
	char *path = NULL;
	int cont = 0, sizepath = 0;
	path = getenv("PATH");
	sizepath = count_spaces(path);
	aux1 = malloc(sizeof(char *) * sizepath);
	tokenized = strtok(path, ":");

	while (tokenized != NULL && cont < sizepath)
        {
                aux1[cont] = tokenized;
                cont++;
                tokenized= strtok(NULL, ":");
        }

	return(aux1);
}

char *after_concat (char **aux1, char *line)
{
	int i, sizepath, j = 0;
	char *concatenated = NULL;
	char *path = NULL;
	sizepath = count_spaces(path);
	path = getenv("PATH");

	for(i = 0; i < sizepath; i++, j++)
	{
		concatenated = _strcat(aux1[j], line);
		printf("%s\n", concatenated);
	}

	return(concatenated);	
}

int main()
{
	char **aux = NULL;
	char *prueba = "/ls";
	char *stringcon = NULL;
	aux = create_aux(aux);

	stringcon = after_concat(aux, prueba);
	printf ("%s\n", stringcon);
	return(0);
}
