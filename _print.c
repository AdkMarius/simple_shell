#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_numbers - print a number in base 10
 * @n: number to display
 * 
 * Return: Number
*/
int print_num(int n)
{
    unsigned int number;
	int i = 0;

	if (n < 0)
	{
		number = -n;
		i = i + _putchar('-');
	}
	else
	{
		number = n;
	}
	if (number / 10 != '\0')
		i = i + print_num(number / 10);
	i = i + _putchar(number % 10 + '0');
	return (i);
}

/**
 * _printp - Prints the prompt in the standar input
 * @prompt: Pointer to the string to be printed
 * @size: Length ot the prompt
 * Return: 0 if success or -1 if fails
 */
int _printf(const char *prompt, unsigned int size)
{
	int written;

	if (isatty(STDIN_FILENO))
	{
		written = write(1, prompt, size);
		if (written == -1)
			return (-1);
	}
		return (0);
}