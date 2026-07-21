#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: accepted characters
 *
 * Return: number of matching bytes at the beginning of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;
	int found;

	i = 0;

	while (s[i] != '\0')
	{
		found = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}

		if (!found)
			break;

		i++;
	}

	return (i);
}
