#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: The string to print
 */
void puts_half(char *str)
{
	int count;
	int i;

	count = 0;

	while (str[count] != '\0')
	{
		count++;
	}

	i = count / 2;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}
