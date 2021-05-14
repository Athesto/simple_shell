#include "../hsh.h"

/**
 * main - test of _strsplit, empty string
 * Return: always 0
 * Output:
 * 5
 */
int main(void)
{
	char msg[] = "";
	char **list;
	int i;

	list = _strsplit(msg);

	i = 0;
	for (i = 0; list[i]; i++)
		printf("%i: %s\n", i, list[i]);

	free(list);
	return (0);
}
