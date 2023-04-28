#include "main.h"

/**
 * findinthepath - looking for a command in the PATH
 * @firstarg: list of arguments
 *
 * Return: 1 if the command is found, otherwhise 0
 */
char *findinthepath(char **av)
{
	char **arr_dir = NULL, *pwd, *path, *str, *dirname;
	unsigned int i = 0, j = 0, lengthdirname = 0;
	struct stat st;

	if (av == NULL)
		return (NULL);
	pwd = _strdup(getenv("PWD"));
	if (pwd == NULL)
		return (NULL);
	path = initializepath(&pwd);
	if (path == NULL)
		return (NULL);
	str = checkdirectorypath(&pwd, &path), i = j = 0;
	arr_dir = fillarguments(str, ":");
	if (arr_dir == NULL)
		return (NULL);
	while (arr_dir[i])
	{
		lengthdirname = _strlen(arr_dir[i]) + _strlen(*av);
		dirname = malloc(sizeof(char) * (lengthdirname + 2));
		if (dirname == NULL)
		{
			free_p(3, path, pwd, str), free_a(arr_dir);
			return (NULL);
		}
		_strcpy(dirname, arr_dir[i]), _strcat(_strcat(dirname, "/"), av[0]);
		if (stat(dirname, &st) == 0)
		{
			*av = _strdup(dirname);
			if (*av == NULL)
			{
				free_p(4, dirname, str, pwd, path), free_a(arr_dir);
				return (NULL);
			}
			free_p(4, dirname, str, pwd, path), free_a(arr_dir);
			return (*av);
		}
		free_p(1, dirname), i++, j = 0;
	}
	free_a(arr_dir), free_p(3, str, pwd, path);
	return (NULL);
}

/**
 * initializepath - initialize path variable
 *
 * @pwd: pointer to pwd
 * Return: value of path
 */
char *initializepath(char **pwd)
{
	char *path;

	path = _strdup(getenv("PATH"));
	if (path == NULL)
	{
		free_p(1, *pwd);
		return (NULL);
	}

	return (path);
}
