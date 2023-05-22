#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define BUFSIZE 1024
#define TOK_BUFSIZE 1024
#define TOK_DELIM " \t\r\n\a"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

int funcion_cd(char **args);
int funcion_exit(char **args);

int loop_shell(void);
char *getpath(char *looking);
int main(int argc, char **argv);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

void retu(char *a);
void signalc(int sig);
int function_cd(char **args);
int function_exit(char **args);
int _strcmp(char *s1, char *s2);
char **split_line(char *buffer);
int _strcmp(char *s1, char *s2);
int stat_arguments(char *argpath);
char **split_line_path(char *buffer);
int execute_arguments(char *argpath);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif
