#include "../hsh.h"
#include <string.h>
#include <stdlib.h>

/**
 * main - test of _getenv, flase Variable
 * Return: always 0
 */

int main(void)
{
	char *path;
	char *path2;

	path2 = getenv("asdfasdf");
	path = _getenv("asdfasdf");
	if (path2 != NULL && path != NULL)
		perror("ERROR: _getenv, NULL test failed\n");
	return (0);
}
