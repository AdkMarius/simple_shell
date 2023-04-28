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

/*#define OUTSIDE 0
#define INSIDE 1
#define BUFFER 1000*/

extern char **environ;

int _print_prompt(const char *prompt, unsigned int size);
void print_error(char **argv);
int shell_loop(char *lineptr);
int _strlen(char *s);

#endif
