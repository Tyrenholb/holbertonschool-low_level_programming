#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - Prints strings separated by a string
 * @separator: String printed between each argument
 * @n: Number of strings passed
 *
 * Return: Nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings;
	unsigned int i;
	char *string;

	va_start(strings, n);

	i = 0;
	while (i < n)
	{
		string = va_arg(strings, char *);

		if (string == NULL)
			printf("(nil)");
		else
			printf("%s", string);

		if (separator != NULL && i < n - 1)
			printf("%s", separator);

		i++;
	}

	va_end(strings);
	printf("\n");
}
