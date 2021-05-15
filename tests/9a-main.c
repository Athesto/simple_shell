#include "../hsh.h"
/**
 * main - test of _getpath, ideal case
 * Return: always 0
 * Output:
 * 5
 */
int main(void)
{
	path_t *path, *runner;

	path = NULL;
	_getpath(&path);
	runner = path;


	while (runner)
	{
		printf("%s\n", runner->val ? runner->val : "(nil)");
		runner = runner->next;
	}
	_freepath(path);
	return (0);
}
