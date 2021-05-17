#ifndef _HSH_H_
#define _HSH_H_
#include <stdio.h> /* printf/puts */
#include <stdlib.h> /* malloc/free/exit */
#include <unistd.h> /* access/execve/fork/isatty */
#include <sys/wait.h> /* wait  */

#define MAGENTA "\033[35m"
#define RSTFMT "\033[0m"
#define PROMPT MAGENTA "jgsh$ " RSTFMT

extern char **environ;

/**
 * struct path_s - linked list of path
 * @val: path name
 * @next: next of path
 */
typedef struct path_s
{
	char *val;
	struct path_s *next;
} path_t;

char **_strsplit(char *);
char *_getenv(const char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
char *_strtok(char *, const char *);
char *_which(char *);
int _getpath(path_t **head);
int _loop(char **);
int _runcmd(char const *, char *const *);
int _strcmp(const char *, const char *);
int _strncmp(const char *, const char *, size_t);
path_t *_addnode(path_t **head, char *str);
size_t _strlen(const char *);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void _freepath(path_t *head);
void _siginthandler(int);
ssize_t _inputblock(char **line, size_t *);

#endif /* _HSH_H_ */
