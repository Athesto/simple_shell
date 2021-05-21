#include "hsh.h"
/**
 * _outputblock - run the command and print
 * @input: input from _getline
 * @argv: values
 * @program_status: ?
 * @counter: ?
 * Return: 0=SUCCESS 1=BREAK 2=CONTINUE 3=NOTFOUND
 */
int _outputblock(char **input, int *program_status, char **argv, int *counter)
{
	char *line = *input_line;
	char **cmd_argv, *full_path;
	int _builtins_status;
	char *strerror1 = "%s: %d: %s: not found\n";
	char *strerror2 = "%s: %d: exit: Illegal number: %s\n";

	cmd_argv = _strsplit(line);
	if (cmd_argv)
	{
		_builtins_status = _builtins(cmd_argv, status);
		if (_builtins_status > 0)
		{
			if (_builtins_status == 3)
			{
				fprintf(stderr, strerror2, argv[0], *counter, cmd_argv[1]);
				if (*status < 0)
					*status = 2;
			}
			free(cmd_argv);
			if (_builtins_status == 1)
				return (1);
			if (_builtins_status == 2 || _builtins_status == 3)
				return (2);
		}
		full_path =  _which(cmd_argv[0]);
		if (!full_path)
		{
			*status = 127;
			fprintf(stderr, strerror1, argv[0], *counter, line);
			free(cmd_argv);
			return (2);
		}
		*status = 0;
		if (_runcmd(full_path, cmd_argv) != 0)
			*status = 2;
		free(full_path);
		free(cmd_argv);
	}
	return (0);
}
