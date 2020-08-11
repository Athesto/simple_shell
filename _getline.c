#include <stdio.h>
/**
 * _getline - ?
 * @lineptr: ?
 * @n: ?
 * @stream: ?
 * Return: Numbers character read
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}
