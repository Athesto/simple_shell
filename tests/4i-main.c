#include "../hsh.h"
#include "unistd.h"

/**
 * main - test of _which, after command "whoami\t\t\t"
 * Return: always 0
 * Output:
 */
int main(void)
{
	char *cmd = "whoami				";
	char *full_path;

	full_path = _which(cmd);
	if (full_path == NULL)
	{
		printf("ERROR: cmd not found\n");
		return (0);
	}
	if (_strcmp(full_path, "/usr/bin/whoami") != 0)
	{
		printf("ERROR: cmd not found\n");
		return (0);
	}
	free(full_path);

	return (0);
}
