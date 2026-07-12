#include "main.h"

/**
* print_diagonal - Draws a diagonal line
* @n: Number of diagonal lines
*
* Return: void
*/
void print_diagonal(int n)
{
	int row = 0;
	int space;

	while (row < n)
	{
		space = 0;

		while (space < row)
		{
			_putchar(' ');
			space++;
		}

		_putchar('\\');
		_putchar('\n');
		row++;
	}

	if (n <= 0)
		_putchar('\n');
}
