#include "hsh.h"
char *_strclear(char const *str, char const *token);

/**
 * _which - locate the command
 * @cmd: command to search
 * Return: full path of the program
 */
char *_which(char *cmd)
{
	char *full_path = NULL;
	char *copy, *copy_cmd, *tmp, *pre_NULL;
	const char *delim = ":";
	int len;

	if (cmd == NULL || *cmd == '\0')
		return (NULL);

	copy_cmd = _strclear(cmd, " \t");

	if (*copy_cmd == '/' && access(copy_cmd, X_OK) == 0)
	{
		return (copy_cmd);
	}

	tmp = copy = _strdup(getenv("PATH"));
	if (!tmp)
	{
		free(copy_cmd);
		return (NULL);
	}

	pre_NULL = tmp;
	while ((tmp = _strtok(pre_NULL, delim)))
	{
		len = _strlen(tmp) + sizeof('/') + _strlen(copy_cmd);
		full_path = malloc(sizeof(*full_path) + len + 1);
		_strcpy(full_path, tmp);
		_strcpy(full_path + _strlen(full_path), "/");
		_strcpy(full_path + _strlen(full_path), copy_cmd);

		if (access(full_path, X_OK) == 0)
			break;

		free(full_path);
		full_path = NULL;
		pre_NULL = NULL;
	}

	free(copy);
	free(copy_cmd);
	return (full_path);
}

/**
 * _strclear - remove start and end characters (needs free)
 * @str: input
 * @token: char to ignore ant start and end
 * Return: NULL if fails, or new strings if works
 *
 */
char *_strclear(char const *str, char const *token)
{
	int len, i, j, k, found;
	char *output;

	len = _strlen(str);
	output = malloc(len + 1);
	for (i = j = 0; i < len; i++)
	{
		for (found = k = 0; token[k] && !found;  k++)
			if (str[i] == token[k])
				found = 1;

		if (!found)
		{
			output[j] = str[i];
			j++;
		}
	}
	output[j] = '\0';
	return (output);

}
