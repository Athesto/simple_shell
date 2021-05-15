#include "hsh.h"

/**
 * _loop - a loop function
 * @argv: arguments of the program
 * Return: 1;
 */
int _loop(char **argv)
{
	char **cmd_argv, *full_path, *line = NULL;
	int counter = 0, status = 0;
	size_t n = 0;
	ssize_t bytes;

	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			printf("%s", PROMPT);
		bytes = _getline(&line, &n, stdin);
		if (bytes == EOF)
		{
			if (isatty(STDIN_FILENO))
				puts("");
			break;
		}

		if (bytes == 1)
			continue;

		cmd_argv = _strsplit(line);
		if (!cmd_argv)
			continue;

		full_path = _which(cmd_argv[0]);
		if (!full_path)
		{
			free(cmd_argv);
			fprintf(stderr, "%s: %d: %s: not found\n", argv[0], counter, line);
			status = 127;
			continue;
		}
		_runcmd(full_path, cmd_argv);
		free(full_path);
		free(cmd_argv);
		status = 0;
	}
	free(line);
	return (status);
}
