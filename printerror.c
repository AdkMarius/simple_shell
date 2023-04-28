#include "main.h"

/**
 * print_error - display error message
 * @argv: argument from standard input
 * 
 * Return: Nothing
*/

void print_error(char **argv)
{
    dprintf(2, "%s: No such file or directory\n", argv[0]);
}