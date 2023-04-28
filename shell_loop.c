#include "main.h"

/**
 * shell_loop - shell program
 * @argv: arguments from standard input
 * @count: counter
 * 
 * Return: 0 if success
*/

int shell_loop(char **argv, char *lineptr)
{
    char *token = NULL, *arg[2];
    pid_t pid;
    int i, status;

    if (argv == NULL || lineptr == NULL)
        return (-1);

    for (i = 0; lineptr[i] != '\0'; i++)
    {
        if (lineptr[i] == ' ' || lineptr[i] == '\t')
        {
            return (-1);
        }
    }

    token = strtok(lineptr, " \n\t");
    arg[0] = token;
    arg[1] = NULL;

    pid = fork();
    if (pid == -1)
    {
        perror("Error\n");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        if (execve(arg[0], arg, environ) == -1)
        {
            print_error(argv);
        }
        exit(0);
    }
    else
        wait(&status);
    
    return (0);
}