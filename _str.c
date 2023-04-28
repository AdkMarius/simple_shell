#include "main.h"

/**
 * number_of_words - count the number of words in a string
 * @str: a string
 * @separator: separator use to split the string
 * Return: number of words
 */
int number_of_words(char *str, char *separator)
{
	int i = 0, etat, nm = 0;

	if (str == NULL)
		return (0);

	etat = INSIDE;
	while (str[i])
	{
		if (str[i] == separator[0] || str[i] == separator[1])
			etat = OUTSIDE;
		else if (etat == OUTSIDE && str[i] != '\n')
		{
			etat = INSIDE;
			++nm;
		}
		i++;
	}
	return (nm);
}