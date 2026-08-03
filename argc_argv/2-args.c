#include <stdio.h>

/**
 *main - Prints all arguments it receives
 *@argc: Number of command line arguments
 *@argv: Array of command line argument strings
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i;

	i = 0;

	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}
