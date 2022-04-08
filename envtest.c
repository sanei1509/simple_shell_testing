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

/*
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
	aux1 = malloc(sizeof(char *) * sizepath + 1);
	tokenized = strtok(path, ":");

	while (tokenized != NULL && cont < sizepath)
        {
                aux1[cont] = tokenized;
                cont++;
                tokenized= strtok(NULL, ":");
        }

	return(aux1);
}

int main()
{
	char *prueba = "/ls";
	int i = 0;
	char **aux = NULL;
	aux = create_aux(aux);

	for (i = 0; aux[i]; i++)
	{
		printf("solo toke: %s\n", aux[i]);
	}

	for (i = 0; aux[i] != NULL; i++)
	{
		aux[i] = _strcat(aux[i], prueba);
		printf("%s\n", aux[i]);
	}

	return(0);
}
