#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **env)
{
	char *var = "PATH";	
	char *path;

	path = _getenv(var, env);

	printf("%s\n", path);

	return(0);
}
