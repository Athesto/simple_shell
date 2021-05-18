#include "hsh.h"

/**
 * _loop - a loop function
 * @argv: arguments of the program
 * Return: 1;
 */
int _loop(char **argv)
{
	char **cmd_argv, *full_path, *line = NULL;
	int counter = 0, status = 0, _builtins_status;
	size_t n = 0;
	ssize_t bytes;

	while (1)
	{
		counter++;
		bytes = _inputblock(&line, &n);
		if (bytes == EOF)
			break;
		if (bytes == 1)
			continue;

		cmd_argv = _strsplit(line);
		if (!cmd_argv)
			continue;
		_builtins_status = _builtins(cmd_argv);
		if (_builtins_status == 1)
		{
			free(cmd_argv);
			break;
		}
		full_path =  _which(cmd_argv[0]);
		if (!full_path)
		{
			status = 127;
			fprintf(stderr, "%s: %d: %s: not found\n", argv[0], counter, line);
			free(cmd_argv);
			continue;
		}

		_runcmd(full_path, cmd_argv);
		status = 0;
		free(full_path);
		free(cmd_argv);
	}
	free(line);
	return (status);
}
