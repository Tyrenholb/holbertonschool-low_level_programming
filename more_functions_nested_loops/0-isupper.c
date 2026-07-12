#include "main.h"

/**
 * _isupper - Checks for an uppercase character
 * @c: Character to check
 *
 * Return: 1 if c is uppercase, otherwise 0
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);

	return (0);
}
