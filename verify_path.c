#include "main.h"
/**
 * verify_path - Verify if the first command can be executed
 * @arguments: Array of entries by the user
 * 
 * Return: 0 if success, or -1 if the exe file doesn't exist
 */
int verify_path(char **arguments)
{
	char *global_path = NULL; /**"   /usr/bin:/bin:/usr/games:/usr/local/games   "*/
	char *global_dup = NULL;
	char *directory = NULL; /**"   /usr/bin    "*/
	char *command_path = NULL; /**"   /usr/bin/touch      "*/
	char *commands[121];
	int exist_stat = -1, i = 0;

	global_path = _getenv("PATH");
	if (global_path == NULL)
		return (-1);
	global_dup = (_strdup(global_path));
	directory = strtok(global_dup, ":");
	if (directory == NULL)
		return (-1);
	free(global_path);
	while (exist_stat == -1 && directory != NULL)
	{
		command_path = append_command(directory, arguments[0]);
		commands[i] = command_path;
		exist_stat = exist_file(commands[i]);
		directory = strtok(NULL, ":");
		i++;
	}
	i--;
	free(global_dup);
	free_grid(commands, i);
	if (exist_stat == 0)
	{
		arguments[0] = commands[i];
		return (0);
	}
	else
	{
		free(commands[i]);
		return (-1);
	}
}

/**
 * append_command - add the directory path and the first command
 * @directory: directory path
 * @command: first command from terminal (stdin)
 * 
 * Return: pointer on an array which contains directory path and the first command
*/
char *append_command(const char *directory, const char *command)
{
    int i, j, len1, len2, len;
    char *directory_command;

    len1 = _strlen(directory);
    len2 = _strlen(command);
    
    len = len1 + len2 + 2;
    directory_command = malloc(sizeof(char) * len);
    if (directory_command == NULL)
        return (NULL);
    
    i = 0;
    while (directory[i])
    {
        directory_command[i] = directory[i];
        i++;
    }
    if (directory_command[i - 1] != '/')
    {
        directory_command[i] = '/';
        i++;
    }
    
    j = 0;
    while (command[j])
    {
        directory_command[i] = command[j];
        i++;
        j++;
    }
    directory_command[i] = '\0';

    return (directory_command);
}

/**
 * _getenv - Get the content of a global variable
 * @global_var: Variable to extract from environ
 * 
 * Return: Pointer to the content of a variable, or NULL if fails
 */
char *_getenv(char *global_var)
{
	int i = 0;
	const char cutter[] = "=";
	char *env_tok, *envdup, *env_tok_dup;

	if (global_var != NULL)
	{
		if (environ == NULL)
			return (NULL);
		envdup = _strdup(environ[i]);
		while (envdup != NULL)
		{
			env_tok = strtok(envdup, cutter);
			if (_strcmp(env_tok, global_var) == 0)
			{
				env_tok = strtok(NULL, cutter);
				env_tok_dup = _strdup(env_tok);
				free(envdup);
				return (env_tok_dup);
			}
			i++;
			free(envdup);
			envdup = _strdup(environ[i]);
		}
	}
	return (NULL);
}
