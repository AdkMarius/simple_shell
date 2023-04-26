#include "main.h"

/**
 * exist - Verify if a file exist
 * @pathname: path to the file
 * 
 * Return: 0 if the file exist or -1 if not
 */
int exist_file(char *pathname)
{
	/*int exist_stat;

	exist_stat = (open(pathname, O_RDONLY));
	if (exist_stat != -1)
	{
		close(exist_stat);
		return (0);
	}
	else
		return (-1);*/

	struct stat st;

	if (stat(pathname, &st) == 0) //System call stat to verify if the file exist
		return (0);
	
	return (-1);
}
