#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints arguments based on a format string
 * @format: String containing the argument type specifiers
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list arguments;
	unsigned int i;
	char *separator;
	char *string;

	va_start(arguments, format);

	i = 0;
	separator = "";

	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", separator, va_arg(arguments, int));
			separator = ", ";
			break;
		case 'i':
			printf("%s%d", separator, va_arg(arguments, int));
			separator = ", ";
			break;
		case 'f':
			printf("%s%f", separator, va_arg(arguments, double));
			separator = ", ";
			break;
		case 's':
			string = va_arg(arguments, char *);

			if (string == NULL)
				string = "(nil)";

			printf("%s%s", separator, string);
			separator = ", ";
			break;
		}

		i++;
	}

	va_end(arguments);
	printf("\n");
}
