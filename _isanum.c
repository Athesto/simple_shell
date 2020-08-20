#include "holberton.h"
/**
 * isanum - check if str is a number;
 * @str: input str
 * Return: 1 if is a number, 0 otherwise
 */
int isanum(char *str)
{
	char *numbers = "1234567890";
	unsigned int len = 0;

	while (str[len])
		len++;
	if (_strspn(str, numbers) == len)
		return (1);

	return (0);
}

/**
 * _strspn - len of a prefix substring
 * @s: - string
 * @accept: - group os chars to search
 * Return: the len of chars that conatins
 */
unsigned int _strspn(char *s, char *accept)
{
	int len = 0;
	char *ps = s, *pa = accept;

	while (*ps)
	{
		while (*pa)
		{
			if (*pa == *ps)
			{
				len++;
				break;
			}
			else
				pa++;
		}
		if (*pa)
		{
			pa = accept;
			ps++;
		}
		else
			break;
	}
	return (len);
}
