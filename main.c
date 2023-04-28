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

    _print_prompt("$ ", 2);
    wget = getline(&lineptr, &n, stdin);
    if (wget == -1)
    {
        free(lineptr);
        return (-1);
    }

    while (wget != -1)
    {
        retour = shell_loop(argv, lineptr);
        if (retour == -1)
        {
            print_error(argv);
        }

        if (retour == 2)
            break;
        _print_prompt("$ ", 2);
        wget = getline(&lineptr, &n, stdin);
        if (wget == -1)
            _print_prompt("\n", _strlen("\n"));
    }

    return (0);
}