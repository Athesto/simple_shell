#include "hsh.h"
void _printenv(void);
/**
 * _builtins - check for builtins functions
 * @argv: input arguments
 * @master_status: the status of exit
 * Return: 0 not found
 */
int _builtins(char **argv, int *master_status)
{
	int status = 0;
	int tmp;
	char *copy_cmd;

	copy_cmd = _strclear(argv[0], " \t");
	if (_strncmp(copy_cmd, "exit", _strlen("exit")) == 0)
	{
		status = 1;
		if (argv[1])
		{
			if (_isnum(argv[1]))
			{
				tmp = _atoi(argv[1]);
				*master_status = tmp;
				if (tmp < 0)
					status = 3;
			}
			else
			{
				status = 3;
				*master_status = -1;
			}
		}
	}

	if (_strncmp(copy_cmd, "env", _strlen("env")) == 0)
	{
		_printenv();
		status = 2;
	}
	free(copy_cmd);
	return (status);
}

/**
 * _printenv - print environment
 */
void _printenv(void)
{
	int i;

	if (!environ)
		return;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

}
