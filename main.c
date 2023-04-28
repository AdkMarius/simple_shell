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
    int retour;

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

        retour = shell_loop(lineptr);
        if (retour == -1)
        {
            print_error(argv);
        }

        free(lineptr);
        lineptr = NULL;
        n = 0;
    }

    return (0);
}