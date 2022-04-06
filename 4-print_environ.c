#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av, char **env)
{
	char *var = "PATH";	
	unsigned int i = 0;
        unsigned int len = strlen(var);

	if (!env || !*var || strchr(var,'='))
	printf("error"); /*NULL;*/
	while ( env[i] && (env[i][len] != '=' || strncmp(var, env[i], len)) )
		i++;
	printf("%s\n", (env[i]) ? env[i] + len + 1 : NULL);

	return(0);
}
