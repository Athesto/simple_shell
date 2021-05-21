#include "hsh.h"
int _printenv(void);
int _bexit(char **argv, int *program_status, char *program, int counter);
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

	if (_strncmp(cmd, "exit", _strlen("exit")) == 0)
	{
		status = _bexit(argv, program_status, program,  counter);
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
 * Return: 1=CONTINUE
 */
int _printenv(void)
{
	int i;

	if (environ)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
	}

	return (CONTINUE);
}
/**
 * _bexit - builtin exit
 * @argv: arguments for the program
 * @program_status: status of the shell (for errors)
 * @program: name of the shell (for errors)
 * @counter: shell counter (for errors)
 * Return: BREAK=1 CONTINUE=2
 */
int _bexit(char **argv, int *program_status, char *program, int counter)
{
	int status, tmp;

	status = BREAK;
	*program_status = 0;
	if (argv[1])
	{
		if (_isnum(argv[1]))
		{
			tmp = _atoi(argv[1]);
			*program_status = tmp;
			if (tmp >= 0)
				return (BREAK);
		}
		_perror(2, program, counter, argv[1]);
		*program_status = 2;
		status = CONTINUE;
	}
	return (status);
}
