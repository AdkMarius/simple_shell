#include "main.h"

/**
 * main - This is a simple shell created by Marius Adjakotan and Charbel ZINGAN for Holberton School
 * @argc: Number of arguments from terminal
 * @argv: double pointer on the different arguments
 * 
 * Return: 0 if success
 */
int main(int argc, char *argv[])
{
	ssize_t nget = 0;
	size_t n = 0;
	char *lineptr = NULL, *arguments[20];
	int counter = 1, vf_stat = 0, exist_stat = 0, exit_stat = 0, blt_stat = 0;

	if (argc != 1)
	{
		dprintf(2, "Usage: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	_printf("$ ", 2); /**prompt mini-shell*/
	nget = getline(&lineptr, &n, stdin);
	while (nget != -1)
	{
		if (*lineptr != '\n')
		{
			fill_args(lineptr, arguments);
			if (arguments[0] != NULL)
			{
				exist_stat = exist_file(arguments[0]); //Call to exist_file to verify if the frist command is a file which exist
				if (exist_stat != 0)
				{
					vf_stat = verify_path(arguments);
					if (vf_stat == 0)
						exit_stat = exec(arguments), free(lineptr), free(*arguments);
					else
					{
					blt_stat = verify_blt(arguments, exit_stat);
					if (blt_stat != 0)
						exit_stat = print_not_found(arguments, counter), free(lineptr);
					}
				}
				else
					exit_stat = exec(arguments), free(lineptr);
			}
			else
				free(lineptr);
		}
		else if (*lineptr == '\n')
			free(lineptr);
		lineptr = NULL, counter++;
		_printf("$ ", 2), nget = getline(&lineptr, &n, stdin);
	}
	last_free(lineptr);
	return (exit_stat);
}
