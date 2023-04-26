#include "main.h"

/**
 * exec - Creates a new child process, executes a command and wait for the child process to update the status
 * @arguments: Array of inputs by the user
 * 
 * Return: 0 if success
 */
int exec(char **arguments)
{
	pid_t child_pid = 0; //Child process id
	int status = 0, exec = 0;

	child_pid = fork(); //Create a child process
	if (child_pid == -1) //Failed of creation of child process
		_printf("failed\n", 7);
	else if (child_pid == 0) //To work with the child process
	{
		exec = execve(arguments[0], arguments, environ); //Excecute the command in the child process
		if (exec == -1)
		{
			exec = 126;
			perror("hsh");
			exit(exec);
		} //End of child process
		exit(0);
	}
	else
		wait(&status); //do wait of parent process
	exec = WEXITSTATUS(status);
	return (exec);
}
