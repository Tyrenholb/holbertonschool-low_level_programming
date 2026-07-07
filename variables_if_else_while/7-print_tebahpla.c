#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase backwars from z - a
 *
 *Return: Always 0 (success)
 */
int main(void)
{
	char ch;

	for (ch = 'z'; ch >='a'; ch--)
	{
		putchar(ch);
	}
	putchar('\n');

	return(0);
}
