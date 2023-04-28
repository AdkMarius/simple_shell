#include "main.h"

/**
 * checkBuiltins - Check for built in commands
 * @av: Argument to check
 * @buff: buffer
 * @count: count
 * Return: 0 success, 1 not found
 */

int checkBuiltins(char **av, char *buff, int count __attribute((unused)))
{

	if (av && *av && buff)
	{
		if (_strcmp("exit", av[0]) == 0 && _strlen(av[0]) == 4)
			return (2);
	}
	return (1);
}
