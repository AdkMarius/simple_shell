#include "main.h"

/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 * 
 * Return: 0 is s1 is equal to s2, < 0 if s1 is less than s2 and > 0 if s1 is greater than s2
*/
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

/**
 * _strdup - Duplicates a string
 * @str: String to be duplicated
 * 
 * Return: Pointer to the duplicated string
 */
char *_strdup(char *str)
{
	unsigned int i, len;
	char *duplicate;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;
	duplicate = (char *) malloc(sizeof(char) * (len + 1));
	if (duplicate == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
	{
		duplicate[i] = str[i];
	}
	return (duplicate);
}

/**
 * _strlen - same function than strlen of string.h library
 * @str: string whose we need to know the length
 * 
 * Return: length of string
*/
size_t _strlen(const char *str)
{
    size_t i;
    
    for (i = 0; str[i]; i++)
        ;
    
    return (i);
}
