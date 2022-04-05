#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
	char *path= "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin";
	unsigned int i;
	char *token;

	i = 0;

	token = strtok(path, ":");	

	while (env[i] != NULL)
	{
		if(strcmp(env[0], "PATH") == 0)
		{
		printf("%s\n", env[i]);
		}
		i++;
	}

	while(token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}

	return (0);
}
