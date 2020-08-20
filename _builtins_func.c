#include "holberton.h"
/**
 * _operator - Builtins operator
 * @args: arguments received
 * Return: 0 if found the command -1 otherwise
 */
int _operator(char **args)
{
	int cont;
	const builtins_t f[] = {
		{"env", get_env},
		{"exit", get_exit},
		{NULL, NULL}
	};


	for (cont = 0; f[cont].cmd; cont++)
	{
		if (_strcmp(args[0], f[cont].cmd) == 0)
		{
			return (f[cont].cmd_f(args));
		}
	}
	return (-1);
}
/**
 * get_env - print enviroment
 * @nothing: this is for compatibility
 * Return: 0 Always
 */
int get_env(char **nothing)
{
	int p_idx;

	for (p_idx = 0; environ[p_idx]; p_idx++)
	{
		_puts(environ[p_idx]);
		_putchar('\n');
	}
	(void)(nothing);
	return (EXIT_SUCCESS);
}

/**
 * get_exit - exit shell
 * @args: this is for compatibility
 * Return: 0 Always
 */
int get_exit(char **args)
{

	if (!args[1])
	{
		exit(EXIT_SUCCESS);
	}

	else if (isanum(args[1]))
	{
		exit(_atoi(args[1]));
	}
	return (2);
}
