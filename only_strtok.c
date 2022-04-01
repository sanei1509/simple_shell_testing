#include <stdio.h>
#include <string.h>

int main()
{
	char string[50] = "Hello world we al ls ls"; 
	char *token;

	token = strtok(string, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
}
