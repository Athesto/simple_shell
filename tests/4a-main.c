#include "../hsh.h"
#include "unistd.h"

/**
 * main - test of _which, ls -> /bin/ls
 * Return: always 0
 * Output:
 * 5
 */
int main(void)
{
	char *cmd = "ls";
	char *full_path = _which(cmd);

	if (_strcmp(full_path, "/bin/ls") != 0)
		printf("ERROR: _which\n%s\n", full_path);
	free(full_path);
	return (0);
}
