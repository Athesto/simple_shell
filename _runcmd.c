#include "hsh.h"
/**
 * _runcmd - fork process and execve
 * @cmd: list of comand and arguments
 * @args: list of comand and arguments
 * Return: 0
 */

int _runcmd(char const *cmd, char *const *args)
{
	int status, error;
	pid_t my_pid;

	my_pid = fork(); /* my_pid@child = 0; my_pid@parent = my_pid@child*/
	if (my_pid == 0)
	{
		status = execve(cmd, args, NULL);
		exit(status);
	}
	else
	{
		error = waitpid(my_pid, &status, 0);
		if (!error)
		{
			perror("ERROR\n");
		}
	}
	return (0);
}
