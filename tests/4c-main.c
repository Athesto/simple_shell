#include "../hsh.h"
#include "unistd.h"

/**
 * main - test of _which, false_ls = NULL
 * Return: always 0
 * Output:
 */
int main(void)
{
	char *cmd = "false_ls";
	char *full_path;

	full_path = _which(cmd);
	if (full_path != NULL)
		printf("ERROR: FALSE CMD IS NULL\n");
	return (0);
}
