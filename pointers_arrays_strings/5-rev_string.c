#include "main.h"

/**
* rev_string - Reverses a string
* @s: The string to reverse
*/
void rev_string(char *s)
{
	char *start;
	char *end;
	char temp;

	start = s;
	end = s;

	if (*s == '\0')
	{
		return;
	}

	while (*end != '\0')
	{
		end++;
	}

	end--;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
