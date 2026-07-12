#include "main.h"

/**
 * more_numbers - Prints the numbers from 0 to 14 ten times
 *
 * Return: void
 */
void more_numbers(void)
{
	int row = 0;
	int num;

	while (row < 10)
	{
		num = 0;
		while (num <= 14)
		{
			if (num > 9)
			{
				_putchar((num / 10) + '0');
			}
			_putchar((num % 10) + '0');
			num++;
		}
		_putchar('\n');
		row++;
	}
}
