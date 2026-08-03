#include <stdio.h>

/**
 *main - Prints the program name
 *@argc: Number of command line arguements
 *@argv: Array of command line arguement strings
 *
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	(void) argc;

	printf("%s\n", argv[0]);

	return (0);

}
