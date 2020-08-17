#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>	/* malloc, exit, free */
#include <stdio.h>	/* printf, getline, stdin */
#include <sys/types.h> /* ssize_t */
#include <sys/wait.h> /* wait */
#include <unistd.h>  /* size_t, write */
#include <string.h> /* strtok */
#include <signal.h> /* signal */
#include <sys/stat.h>	/* stat */

extern char **environ;

typedef struct stat stat_t;

int _getline(char **lineptr, size_t *n, FILE *stream);
void _puts(char *str);
int _putchar(char c);
char *_getpath(void);
#endif /* _HOLBERTON_H_ */
