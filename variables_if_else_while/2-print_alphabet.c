#include <stdio.h>

/**
 * main - entry point
 *
 * prints the alphabet in lowercase followed by a new line.
 * can only use putchar twice
 *
 * return: always 0
 */
	int main(void)
	{
		char ch;

		for (ch = 'a'; ch <= 'z'; ch++)
		{
			putchar(ch);
		}
		putchar('\n');

		return (0);
	}
