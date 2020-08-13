#include <stdio.h> /* puts, printf */
#include <string.h> /* strtok, */
#include <stdlib.h> /* malloc, free */

/**
 * _getpath - get path from the env variable
 * _getpath use malloc inside and need a free
 * @env: env list
 * Return: path list
 */
char **_getpath(char **env)
{
	char **ptr = env;	/* seeking pointer */
	char **path;		/* output list */
	int p_idx;			/* path index*/
	/* check invalid input */
	if (!ptr || !*ptr)	/* check if env exist and if list is not NULL */
		return (NULL);

	/* search PATH variable in ENV */
	while (strncmp(*ptr, "PATH=", 5)) /* compare the 5 first char */
		ptr++;
	/* puts(*ptr); */ /* Debug: display PATH variable */

	/* alloc memory for first path's directory */
	path = malloc(sizeof(*path));
	if (!path)
		return (NULL);

	p_idx = 0; /* initialize path index */
	strtok(*ptr, "="); /* set strtok pointing at first value of path */
	while ((path[p_idx] = strtok(NULL, ":"))) /**/
	{
		p_idx++; /* set index to the next position */
		/* reallocate memory for new position*/
		path = realloc(path, (p_idx + 1) * sizeof(*path));
		if (!path)
			return (NULL);
	}
	return (path);
}
