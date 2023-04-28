#include "main.h"

/**
 * _print_prompt - Prints the prompt in the standar input
 * @prompt: Pointer to the string to be printed
 * @size: Length ot the prompt
 * 
 * Return: 0 if success or -1 if fails
 */
int _print_prompt(const char *prompt, unsigned int size)
{
	ssize_t n;

	if (isatty(STDIN_FILENO))
	{
		n = write(STDIN_FILENO, prompt, size);
		if (n == -1)
			return (-1);
	}

	return (0);
}