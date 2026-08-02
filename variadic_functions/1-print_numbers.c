#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers separated by a string
 * @separator: String printed between numbers
 * @n: Number of integers passed
 *
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;

	va_start(numbers, n);

	i = 0;
	while (i < n)
	{
		printf("%d", va_arg(numbers, int));

		if (separator != NULL && i < n - 1)
			printf("%s", separator);

		i++;
	}

	va_end(numbers);
	printf("\n");
}
