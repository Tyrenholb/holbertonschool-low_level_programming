# include <stdio.h>

/**
 * main - Prints all the numbers of base 16 in lowercase, followed by a new line.
 *
 * Return : Always 0 (Success)
 */
int main(void)
{
	char ch;
	char nu;

	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}
	for (nu = '0'; nu <= '9'; ch++)
	{
		putchar(nu);
	}
	putchar('\n');

	return (0);
}

