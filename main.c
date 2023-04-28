#include "main.h"

/**
 * main - main of simple shell
 * @argc: number of arguments
 * @argv: double pointer
 * 
 * Return: 0
*/
int main(int argc __attribute__((unused)), char *argv[])
{
    char *lineptr = NULL;
    size_t n;
    ssize_t wget;
    int retour, count = 0, status;
    pid_t pid;

    while (1)
    {
        _print_prompt("$ ", 2);
        wget = getline(&lineptr, &n, stdin);
        if (wget == -1)
        {
            free(lineptr);
            _print_prompt("\n", _strlen("\n"));
            exit(EXIT_SUCCESS);
        }

        retour = shell_loop(lineptr, argv, count);
		if (retour == 2)
		{
			count++;
			pid = fork();
			if (pid == -1)
			{
				perror("Error\n");
				return (EXIT_FAILURE);
			}
			if (pid != 0)
			{
				wait(&status);
				return (127);
			}
			else
				continue;
		}
		if (retour != 0)
			break;
		count++;
	}
    return (0);
}