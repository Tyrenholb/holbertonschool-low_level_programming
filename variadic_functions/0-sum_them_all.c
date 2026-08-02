#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - Returns the sum of all its parameters
 * @n: Number of additional parameters
 *
 * Return: Sum of all parameters, or 0 if n is 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;
	int sum;

	if (n == 0)
		return (0);

	sum = 0;
	va_start(numbers, n);

	i = 0;
	while (i < n)
	{
		sum += va_arg(numbers, int);
		i++;
	}

	va_end(numbers);

	return (sum);
}
