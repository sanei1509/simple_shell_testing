#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *_getenv(const char *var, char **env)
{	
	unsigned int i = 0;
	unsigned int len = strlen(var);
	
	if (!env || ! *var || strchr(var,'='))
		return (NULL);
	else
	while (env[i] && (env[i][len] != '=' || _strncmp(var, env[i], len)))
		i++;

	return (env[i]) ? (env[i] + len + 1) : (NULL);
}


int main (int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **env)
{
        char *var = "PATH";
        char *path = NULL;
        char *prueba = "/ls", *concatenated = NULL;
        char **aux = NULL;
        int cont = 0, sizepath = 0, j = 0, c = 0;
        char *tokenized = NULL;

        path = _getenv(var, env);
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
	printf("******************************");
        concatenated = _strcat(aux[1], prueba);
	concatenated = _strcat(aux[2], prueba);
	concatenated = _strcat(aux[3], prueba);
	
        /*printf("%s\n",aux[0]);*/

        for (c = 0; c < sizepath; c++)
        {
                printf("no se q:%s\n", aux[c]);
        }

	/*
        printf("%d\n", sizepath);
        free(aux);
        printf("%s\n", concatenated);
	*/
	return(0);
}

