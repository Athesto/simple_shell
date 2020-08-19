#include "holberton.h"
/**
 * _strcpy - Entry point
 * @dest: Destination string
 * @src: Source string
 * Return: Dest string
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);
}
