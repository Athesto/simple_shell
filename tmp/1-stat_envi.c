#include "../holberton.h"
#include <sys/types.h>	/* stat */
#include <sys/stat.h>	/* stat */
#include <unistd.h>		/* stat */

char *getFullcmd(char *cmd);
void printFullcmd(char *cmd_FULLPATH);
/**
 * main:
*/
int main(void)
{
	char *cmds[] =
	{
		"ls",
		"/bin/ls",
		"lsdlsd",
		NULL
	}; /* list of commands */
	int c_idx; /* cmds index */
	char *cmd_FULLPATH; /* pointer to full command */

	/* read full command */
	for (c_idx = 0; cmds[c_idx]; c_idx++)
	{
		cmd_FULLPATH = getFullcmd(cmds[c_idx]);
		printFullcmd(cmd_FULLPATH);
	}
	return (0);
}
/**
 * getFullcmd - search the full path of a command in the PATH
 * @cmd: pointer to input command
 * Return: A pointer with the full PATH command 
 * if exist otherwise it return a  NULL
 */
char *getFullcmd(char *cmd)
{
	char *fullcmd = NULL; /* full command path */
	struct stat st; /* A structure with the file status information */ 
	if (!cmd)
	{
		return (NULL);
	}
	strcat(fullcmd, cmd);
	if (stat(fullcmd, &st) == 0) /* check if file exist in full command */
	{
		return (fullcmd);
	}
	return (NULL);
}

void printFullcmd(char *cmd_FULLPATH)
{
	if(cmd_FULLPATH)
	{
		printf("%s\n", cmd_FULLPATH);
	}
	else
	{
		perror("command not found");
	}

}