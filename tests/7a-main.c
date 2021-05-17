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
		"/usr/bin/whoami",
		NULL
	};

	printf("start\n");
	_runcmd(cmd[0], cmd);
	printf("end\n");
	return (0);
}
