#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase and uppercase.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;
	char cch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}
	for (cch = 'A'; cch <= 'Z'; cch++)
	{
		putchar(cch);
	}
	putchar('\n');

	return (0);
}
