#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

extern char **environ;

int _strcmp(const char *s1, const char *s2);
int verify_path(char **arguments);
char *_strdup(char *str);
char *append_command(const char *dir_path, const char *command);
int exec(char **arguments);
int fill_args(char *entry, char **arguments);
int print_num(int n);
size_t _strlen(const char *str);
int print_not_found(char **arguments, int counter);
char *_getenv(char *global_var);
int _printf(const char *prompt, unsigned int size);
int _putchar(char c);
int exist_file(char *pathname);
void free_grid(char **grid, int heigth);
void last_free(char *entry);
int verify_blt(char **arguments, int exit_stat);

#endif
