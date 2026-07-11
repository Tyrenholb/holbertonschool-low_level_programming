#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number.
 * @n: Number to check.
 *
 * Return: Last digit of n.
 */
int print_last_digit(int n)
{
	int digit;

	digit = n % 10;

	if (digit < 0)
	{
		digit = -digit;
	}

	_putchar(digit + '0');

	return (digit);
}
