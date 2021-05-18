#include "hsh.h"
/**
 * _outputblock - run the command and print
 * @input_line: values
 * @argv: values
 * @status: ?
 * @counter: ?
 * Return: 0=nothing 1=break 2=continue
 */
int _outputblock(char **input_line, char **argv, int *status, int *counter)
{
	char *line = *input_line;
	char **cmd_argv, *full_path;
	int _builtins_status;
	char *strerror = "%s: %d: %s: not found\n";

	cmd_argv = _strsplit(line);
	if (cmd_argv)
	{
		_builtins_status = _builtins(cmd_argv);
		if (_builtins_status > 0)
		{
			free(cmd_argv);
			if (_builtins_status == 1)
				return (1);
			if (_builtins_status == 2)
				return (2);
		}
		full_path =  _which(cmd_argv[0]);
		if (!full_path)
		{
			*status = 127;
			fprintf(stderr, strerror, argv[0], *counter, line);
			free(cmd_argv);
			return (1);
		}
		*status = 0;
		if (_runcmd(full_path, cmd_argv) != 0)
			*status = 2;
		free(full_path);
		free(cmd_argv);
	}
	return (0);
}
