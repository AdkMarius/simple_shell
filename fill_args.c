#include "main.h"

/**
 * fill_args - Fill an array with every input typed by the user
 * @entry: String with the input
 * @arguments: Array to be filled
 * 
 * Return: Length of the array
 */

int fill_args(char *entry, char **arguments)
{
	int i = 0;
	char *token, *value = entry, *command;

	command = strtok(entry, "\n\t\r "); //strtok allows to extract the token from on delimiters (here \n\t\r )
	arguments[i] = command;
	while (value != NULL)
	{
		++i;
		token = strtok(NULL, "\n\t\r ");
		value = token;
		arguments[i] = token;
	}
	arguments[i] = NULL;
	return (i);
}
