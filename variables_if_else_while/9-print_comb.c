#include <stdio.h>

/**
 * main - Prints all numbers with commas.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int nu;

	for (nu = '0'; nu <= '9'; nu++)
	{
		putchar(nu);
		if (nu < '9')
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return(0);
}
