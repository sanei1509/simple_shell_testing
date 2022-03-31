#include <stdio.h>
#include <unistd.h>  /*necesario para fork()*/

/*Pruebas de bifurcaciones*/
int main(void)
{

	int dady_process;
	pid_t pid_return_fork;


	printf("-> Proceso principal = %d \n", getpid());
	pid_return_fork = fork();

	printf("-> Proceso principal (padre) = %d, Proceso secundario %d\n", dady_process, pid_return_fork);
	
	//validacion
	if (pid_return_fork > 0)
		printf("hijo creado\n");
	if (pid_return_fork == 0)
	{
		printf("estoy en el hijo\n");
		dady_process = getppid();
		printf("%d", dady_process);
	}
	if (pid_return_fork < 0)
		printf("-1 - >ERROR\n");

	return (0);
}
