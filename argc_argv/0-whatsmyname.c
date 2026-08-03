#include <stdio.h>

/**
 *@argc: void.
 *@argv: used to printf the string.
 *Return: always 0
 */

int main(int argc, char *argv[])
{
	(void) argc;

	printf("%s\n", argv[0]);

	return (0);

}
