#include "main.h"
/**
 * shell_loop - shell program
 * @argv: name of executable
 * @count: counter
 * @lineptr: arguments from terminal
 * 
 * Return: 0
 */
int shell_loop(char *lineptr, char **argv, int count)
{
	char **av = NULL;

	av = fillarguments(lineptr, " \t"), count++;
	if (av[0] == NULL)
	{
		free_p(1, lineptr), free_a(av);
		return (0);
	}
    if (av[0][0] != '/' && av[0][0] != '.')
	{
		print_error(argv);
        return (2);
	}
	if (processus(argv, av, lineptr) != 0)
	{
		free_p(1, lineptr), free_a(av);
		return (2);
	}
	//free_p(1, lineptr), free_a(av);
	return (0);
}
