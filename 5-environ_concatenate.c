nclude <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *_getenv(const char *var, char **env)
{	
	unsigned int i = 0;
	unsigned int len = strlen(var);
	
	if (!env || ! *var || strchr(var,'='))
		return (NULL);
	else
	while (env[i] && (env[i][len] != '=' || strncmp(var, env[i], len)))
		i++;

	return (env[i]) ? (env[i] + len + 1) : (NULL);
}


int main ()
{
        char *var = "PATH";
        char *path = NULL;
        char *prueba = "/ls", *concatenated = NULL;
        char **aux = NULL;
        int cont = 0, sizepath = 0, j = 0;
        
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


                return(0);
}

