#ifndef _MAIN_H_
#define _MAIN_H_

#define SIZE_MAX 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <signal.h>
#include <inttypes.h>
#include <errno.h>
#include <fcntl.h>

#define OUTSIDE 0
#define INSIDE 1
#define BUFFER 1000

extern char **environ;

int _print_prompt(const char *prompt, unsigned int size);
void print_error(char **argv);
int shell_loop(char *lineptr, char **argv, int count);
int number_of_words(char *str, char *separator);
char **fillarguments(char *buf, char *separator);
void free_p(const unsigned int n, ...);
void free_a(char **arr);
int processus(char **argv, char **av, char *buf);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int number_of_words(char *str, char *separator);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strstr(char *haystack, char *needle);
char *checkdirectorypath(char **pwd, char **path);
char *initializepath(char **pwd);
char *updatethepath(char *path, char *pwd);
char *findinthepath(char **av);
int checkBuiltins(char **av, char *buff, int count __attribute((unused)));

#endif
