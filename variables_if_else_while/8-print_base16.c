#include <stdio.h>

/**
 * main - Prints all the chars of base 16 in lowercase, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;
	char nu;

	for (nu = '0'; nu <= '9'; nu++)
	{
		putchar(nu);
	}
	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');

	return (0);
}

