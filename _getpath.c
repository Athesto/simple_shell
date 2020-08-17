#include "holberton.h"
/**
 * _getpath - get the PATH from the ENV variable
 * _getpath use malloc internally and need to be free with free()
 * Return: A list with the elements of the PATH
 */
char *_getpath(void)
{
	int e_idx;		/* enviroment index */
	/* check invalid input */
	if (!environ || !*environ)	/* check if env exist and if list is not NULL */
		return (NULL);

	/* search PATH variable in ENV */
	e_idx = 0;
	while (strncmp(environ[e_idx], "PATH=", 5)) /* compare the 5 first char */
		e_idx++;

	return (environ[e_idx]);
}
