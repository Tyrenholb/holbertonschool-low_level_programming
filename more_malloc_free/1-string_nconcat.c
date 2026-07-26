#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of bytes from s2 to concatenate.
 *
 * Return: Pointer to the new string, or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int i;
	unsigned int j;
	char *str;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		n = len2;

	str = malloc(sizeof(char) * (len1 + n + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		str[i] = s1[i];

	for (j = 0; j < n; j++)
		str[len1 + j] = s2[j];

	str[len1 + j] = '\0';

	return (str);
}
