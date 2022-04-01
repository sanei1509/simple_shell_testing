#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
	char * argv[] = {"/bin/ls", NULL, NULL, NULL};
	char * env[] = {NULL};

	if (execve(argv[0], argv, env) == -1)
		perror("comando no valido");
	else
	{
		printf("Ruta encontrada avanzamos a la flag");
	}
}

