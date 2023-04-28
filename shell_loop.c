#include "main.h"

/**
 * shell_loop - shell program
 * @argv: arguments from standard input
 * @count: counter
 * 
 * Return: 0 if success
*/

int shell_loop(char *lineptr)
{
    char *token = NULL, *arg[2];
    pid_t pid;
    int i, status;

    if (lineptr == NULL)
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

    if (exist_file(arg[0]) == -1)
    {
        return (-1);
    }
    
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
            return (-1);
        }
        exit(0);
    }
    else
        wait(&status);
    
    return (0);
}