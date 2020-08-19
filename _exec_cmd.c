#include "holberton.h"
/**
 * exec_cmd - Function that executes a command
 * @cmd: Command for execute
 * @args: Arguments receive
 * Return: 0 success
 */
int exec_cmd(char *cmd, char **args)
{
	char *ptr_dir;/* --> Pointer for directories in PATH*/
	char *cp_PATH;/* --> PATH copy, recieves the list of elements in PATH */
	char *tmp;	/* --> Temporal variable wich allocates memory*/
	stat_t st;	/* --> A structure with the file status information */

	if (!cmd || !*cmd || !args || !*args || !**args)
	{
		exit(EXIT_SUCCESS);
	}
	if (_operator(args) == 0)
	{
		return (0);
	}
	if (stat(cmd, &st) == 0) /* check if file exist in full command */
	{
		return (execve(cmd, args, NULL));
	}
	cp_PATH = _getpath();	/* cp_PATH pointing to PATH in ENVIRON */
	cp_PATH = strdup(cp_PATH);
	ptr_dir = cp_PATH;	/* ptr_dir pointing to cp_PATH */
	/* move ptr_dir after "PATH=" in the cp_PATH */
	ptr_dir = strtok(cp_PATH, "=");
	tmp = malloc(1024);
	while ((ptr_dir = strtok(NULL, ":")))
	{
		strcpy(tmp, ptr_dir);
		tmp = _strcat(tmp, "/");
		tmp = _strcat(tmp, cmd);
		/* check if file exist in full command */
		if (stat(tmp, &st) == 0)
		{
			free(cp_PATH); /* free cp_PATH */
			return (execve(tmp, args, NULL));
		}
	}
	free(tmp);
	free(cp_PATH); /* free cp_PATH */
	return (-1); /* cmd not found */
}
