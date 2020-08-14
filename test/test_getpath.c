#include "../holberton.h"
/**
 * main - testing funtion _getpath()
 * Return: Always 0
 */
int main (void)
{
	char **myPATH; 	/* PATH */
	int p_index; 	/* myPATH index */

	myPATH = _getpath();
	p_index = 0;
	while(myPATH[p_index])
	{
		printf("%s\n", myPATH[p_index]);
		p_index++;
	}
	return (0);
} 
