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
	int retour = 0;

	av = fillarguments(lineptr, " \t"), count++;
	if (av[0] == NULL)
	{
		free_p(1, lineptr), free_a(av);
		return (0);
	}
	if (av[0][0] != '/' && av[0][0] != '.')
	{
		retour = checkBuiltins(av, lineptr, count);
		if (retour == 0 || retour == 2)
		{
			free_p(1, lineptr), free_a(av), retour == 0 ? (retour = 0) : (retour = 1);
			return (retour);
		}
		if (!(findinthepath(av)))
		{
			print_error(argv), free_p(1, lineptr), free_a(av);
			return (2);
		}
		else
		{
			processus(argv, av, lineptr);
			return (0);
		}
	}
	if (processus(argv, av, lineptr) != 0)
	{
		free_p(1, lineptr), free_a(av);
		return (2);
	}
	free_p(1, lineptr), free_a(av);
	return (0);
}