#include <stdio.h>
#include "lib-linked/lists.h"
#include "../../holberton.h"
#include <string.h>
/**
 * main - ?
 * Return: ?
 */ 
int main(void)
{
	list_t *head = NULL;	/* head of the list */
	char *cp_PATH; 			/* PATH split */
	char *PATH_backup;		/* PATH variable */
	char *tmp;				/* ? */

	cp_PATH = _getpath();	/* cp_PATH pointing to PATH in ENV */
	PATH_backup = cp_PATH;	/* backup of pointer */
	/* move cp_PATH to the next position after "PATH=" in the PATH */
	while ((*cp_PATH++) != '=') 
		;

	/* duplicate string at cp_PATH and cp_PATH points to new location */
	cp_PATH = strdup(cp_PATH); 
 	/* changed 1rst ':' to '\0' and tmp = cp_PATH */
	tmp = strtok(cp_PATH, ":"); 	
	/* duplicate the string pointed by tmp into a node at end of list */
	add_node_end(&head, tmp); 

	/* 
	 * 1: set the frist ':' into '\0' of cp_PATH's leaftover
	 * 2: set tmp pointing to the new position
	 * 3: check if tmp is NULL
	*/	
	while ((tmp = strtok(NULL, ":")))
	{
		/* duplicate the string pointed by tmp into a node at end of list */
		add_node_end(&head, tmp);
	}
	
	print_list(head);	/* print list */
	free_list(head);	/* free list */
	
	puts(PATH_backup);	/* Debug: PATH_*/
	puts("=========");
	puts(cp_PATH);

	free(cp_PATH);
	(void)head;
	return (0);
}
