#include "../holberton.h"
int exec_cmd(char *cmd, char **args);
/**
 * main - ?
 * Return: ?
 */
int main(void)
{
	char *cmds[] = {"ls", "-l"};
	exec_cmd(cmds[0],cmds);
	return (0);
}
/**
 * exe_cmd - Function that executes a command
 * @cmd: command for execute
 * @args: arguments received
 * Return: ?
 */
int exec_cmd(char *cmd, char **args)
{
	char *ptr_dir;		/* --> Pointer for directories in PATH*/
	char *cp_PATH;		/* --> PATH copy, recieves the list of elements in PATH */
	char *tmp;			/* --> Temporal variable wich allocates memory*/
	struct stat st; 	/* --> A structure with the file status information */ 

	if (stat(cmd, &st) == 0) /* check if file exist in full command */
	{
		if (execve(cmd, args, NULL) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	
	cp_PATH = _getpath();	/* cp_PATH pointing to PATH in ENVIRON */
	
	cp_PATH = strdup(cp_PATH);
	ptr_dir = cp_PATH;	/* ptr_dir pointing to cp_PATH */
	/* move ptr_dir after "PATH=" in the cp_PATH */
	
	ptr_dir = strtok(cp_PATH, "=");
	
	tmp = malloc(1024);
	
	while((ptr_dir = strtok(NULL, ":")))
	{
		strcpy(tmp, ptr_dir);
		tmp = strcat(tmp, "/");
		tmp = strcat(tmp, cmd);
		
		if (stat(tmp, &st) == 0) /* check if file exist in full command */
		{
			if (execve(tmp, args, NULL) == -1)
			{
				free(tmp);
				free(cp_PATH); /* free cp_PATH */
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
		}
	}
	free(tmp);
	free(cp_PATH); /* free cp_PATH */
	return (0);
}
