#include "../hsh.h"

/**
 * main - test of _strsplit, NULL string
 * Return: always 0
 * Output:
 * 5
 */
int main(void)
{
	char *msg = NULL;
	char **list;
	int i;

	list = _strsplit(msg);
	if (!list)
		return (0);

	i = 0;
	for (i = 0; list[i]; i++)
		printf("%i: %s\n", i, list[i]);

	free(list);
	return (0);
}
