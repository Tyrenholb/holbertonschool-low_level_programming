#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated copy of a string
 * @str: String to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	copy = malloc((len + 1) * sizeof(char));

	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = str[i];

	return (copy);
}
