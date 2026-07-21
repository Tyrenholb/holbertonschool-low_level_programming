#include "main.h"

/**
 * print_chessboard - prints an 8 by 8 chessboard
 * @a: chessboard to print
 *
 * Return: nothing
 */
void print_chessboard(char (*a)[8])
{
	int row;
	int column;

	row = 0;
	while (row < 8)
	{
		column = 0;
		while (column < 8)
		{
			_putchar(a[row][column]);
			column++;
		}
		_putchar('\n');
		row++;
	}
}
