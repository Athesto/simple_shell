#include "hsh.h"
/**
 * _builtins - check for builtins functions
 * @argv: input arguments
 * Return: 0 not found
 */
int _builtins(char **argv)
{
	int status = 0;
	char *copy_cmd;

	copy_cmd = _strclear(argv[0], " \t");
	if (_strncmp(copy_cmd, "exit", _strlen("exit")) == 0)
	{
		status = 1;
	}
	free(copy_cmd);
	return (status);
}

