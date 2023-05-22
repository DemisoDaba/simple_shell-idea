#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define BUFSIZE 1024
#define TOK_BUFSIZE 1024
#define TOK_DELIM " \t\r\n\a"

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

int funcion_cd(char **args);
int funcion_exit(char **args);

int main(int argc, char **argv);
int _strcmp(char *s1, char *s2);
char *getpath(char *looking);
char *_strcat(char *dest, char *src);
int loop_shell(void);
char **split_line_path(char *buffer);
char **split_line(char *buffer);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int execute_arguments(char *argpath);
int stat_arguments(char *argpath);
int _strcmp(char *s1, char *s2);
int function_cd(char **args);
int function_exit(char **args);
void retu(char *a);
void signalc(int sig);
int _strcmp(char *s1, char *s2);
#endif
