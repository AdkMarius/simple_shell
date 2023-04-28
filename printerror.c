#include "main.h"

/**
 * print_error - display error message
 * @argv: argument from standard input
 * 
 * Return: Nothing
*/
void print_error(char **argv)
{
    char message[] = "No such file or directory\n";

    write(STDERR_FILENO, *argv, _strlen(*argv));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, message, _strlen(message));
}

/**
 * _strlen - count the character
 * @s: string
 * 
 * Return: length
*/
int _strlen(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        ;
    
    return (i);
}