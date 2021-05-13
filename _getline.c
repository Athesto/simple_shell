#include <stdio.h>
/**
 * _getline - this is call getline and remove the newline
 * @lineptr: pointer to line
 * @n: size
 * @stream: output file
 * Return: size ot line
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *local_line;
	ssize_t bytes;
	int i;

	bytes = getline(lineptr, n, stream);
	if (bytes == EOF)
		return (bytes);

	local_line = *lineptr;
	for (i = 0; local_line[i]; i++)
	{
		if (local_line[i] == '\n')
			local_line[i] = '\0';
	}
	return (bytes);
}
