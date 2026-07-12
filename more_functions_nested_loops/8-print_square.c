#include "main.h"

/**
* print_square - Prints a square using the character #
* @size: Size of the square
*
* Return: void
*/
void print_square(int size)
{
	int row = 0;
	int column;

	while (row < size)
	{
		column = 0;

		while (column < size)
		{
			_putchar('#');
			column++;
		}

		_putchar('\n');
		row++;
	}

	if (size <= 0)
		_putchar('\n');
}
