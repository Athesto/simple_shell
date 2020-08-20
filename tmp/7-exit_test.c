#include "holberton.h"

/**
 * 
 * Description: errores [pos-num, 2, 126, 127]
 * success: [0]
 */

int error_m(char **args)
{
	int i = 0; 

	if (args[i] == 126) 
	{
		notexect(args);
	}
	if (args[i] == 2)
	{

	}
	if (args[i] == 127)
	{
		notfound(args)
	}
}
int notfound()
{
	_strcat(errmsg, shellname);
	_strcat(errmsg, ": ");
	strcatnum(errmsg, counter);
	_strcat(errmsg, ": ");
	_strcat(errmsg, args[0]);
	_strcat(errmsg, ": not found\n");
	_fputs(STDERR_FILENO, errmsg);
}
