#include <stdio.h>
#include "lib-linked/lists.h"
#include "../../holberton.h"
#include <string.h>
/**
 * main - get PATH as Linked list
 * Return: 0 Always
 */ 
int main(void)
{
	list_t *head = NULL;	/* head of the list */
	char *cp_PATH; 			/* PATH split */
	char *PATH_backup;		/* PATH variable */
	char *tmp;				/* ? */

	cp_PATH = _getpath();	/* cp_PATH pointing to PATH in ENV */
	PATH_backup = cp_PATH;	/* backup of pointer */
	/* move cp_PATH after "PATH=" in the PATH variable */
	/*
	 * 1. eval *cp_PATH  != '='
	 * 2. increase cp_PATH
	 * 3. repeat or skip
	 */
	while ((*cp_PATH++) != '=')
		;
	/* duplicate the string pointd by cp_PATH and cp_PATH points to new location */
	cp_PATH = strdup(cp_PATH);
 	/* 1: changed 1rst ':' to '\0' (this operation split cp_PATH at ':')
	 * 2: tmp points to left side of splited cp_PATH */ 
	tmp = strtok(cp_PATH, ":");
	/* duplicate the string pointed by tmp and add it to node at end of list */
	add_node_end(&head, tmp);
	/* 
	 * 1: set the next ':' into '\0' of right side of cp_PATH 
	 * (this operation split the right side of cp_PATH)
	 * 2: tmp points to the left side of the slipted string 
	 * 3: check if tmp is NULL
	 * 4: repeat until convert all ':' into '\0'
	*/	
	while ((tmp = strtok(NULL, ":")))
	{
		/* duplicate the string pointed by tmp into a node at end of list */
		add_node_end(&head, tmp);
	}
	print_list(head);	/* print list */
	free_list(head);	/* free list */
	
	free(PATH_backup); 	/* free PATH */
	return (0);
}
