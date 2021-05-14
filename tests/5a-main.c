#include "../hsh.h"

/**
 * main - test of _strdup, Ideal case
 * Return: always 0
 * Output:
 * 5
 */
int main(void)
{
	char *msg = "betty";
	char *duplicated = _strdup(msg);

	printf("%s\n", duplicated);
	free(duplicated);
	return (0);
}
