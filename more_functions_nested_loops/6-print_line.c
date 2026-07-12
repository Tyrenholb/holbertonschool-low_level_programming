#include "main.h"

/**
* print_line - Draws a straight line in the terminal
* @n: Number of underscores to print
*
* Return: void
*/
void print_line(int n)
{
	int count = 0;

	while (count < n)
	{
		_putchar('_');
		count++;
	}
	_putchar('\n');
}
