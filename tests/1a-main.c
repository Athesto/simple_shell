#include "../hsh.h"
#include <string.h>
#include <stdlib.h>

/**
 * main - test of _getenv, Ideal case
 * Return: always 0
 */

int main(void)
{
	char *path;
	char *path2;

	path2 = getenv("PATH");
	path = _getenv("PATH");
	if (strcmp(path, path2) != 0)
		printf("_getenv(): %s\ngetenv(): %s\n----\n", path, path2);

	return (0);
}
