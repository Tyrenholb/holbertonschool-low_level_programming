#include "main.h"

/**
* print_triangle - Prints a triangle
* @size: Size of the triangle
*
* Return: void
*/
void print_triangle(int size)
{
	int row = 1;
	int space;
	int hash;

	while (row <= size)
	{
		space = size - row;
		while (space > 0)
		{
			_putchar(' ');
			space--;
		}

		hash = 0;
		while (hash < row)
		{
			_putchar('#');
			hash++;
		}

		_putchar('\n');
		row++;
	}

	if (size <= 0)
		_putchar('\n');
}
