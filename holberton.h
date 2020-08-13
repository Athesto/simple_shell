#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>	/* malloc, exit, free */
#include <stdio.h>	/* printf, getline, stdin */
#include <sys/types.h> /* ssize_t */
#include <sys/wait.h> /* wait */
#include <unistd.h>  /* size_t, write */
#include <string.h> /* strtok */
#include <signal.h> /* signal */

int _getline(char **lineptr, size_t *n, FILE *stream);
void _puts(char *str);
int _putchar(char c);
#endif /* _HOLBERTON_H_ */
