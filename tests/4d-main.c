#include "../hsh.h"
#include "unistd.h"

/**
 * main - test of _which, NULL -> NULL
 * Return: always 0
 * Output:
 */
int main(void)
{
	char *cmd = NULL;
	char *full_path;

	full_path = _which(cmd);
	if (full_path != NULL)
		printf("ERROR: FALSE CMD NOT NULL\n");
	return (0);
}
