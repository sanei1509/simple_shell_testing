#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>


int _putchar(char c);
int _strncmp(const char s1[], const char s2[], size_t n);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

int count_paths(char *aux_line);
int count_espacios(char *aux_line);

int getpadre_id(void);
int gethijo_id(void);


char **return_env(char **environ);
char *_getenv(char *var, char **environ);
char **create_aux (char **aux1, char **env_aux);
char* compare_path(char **array, char *cmd);









#endif
