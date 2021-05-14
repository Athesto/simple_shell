#include "../hsh.h"
#include <string.h>

/**
 * main - test of _runcmd
 * Return: always 0
 * Output:
 * 5
 */
int main(void)
{
	char *cmd[] = {
		"uname",
		"-s",
		NULL
	};
	char *full_path;

	full_path = _which(cmd[0]);
	if (!full_path)
		perror("ERROR: path\n");
	_runcmd(full_path, cmd);
	free(full_path);
	return (0);
}
