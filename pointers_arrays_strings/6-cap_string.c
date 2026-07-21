#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to the string
 */
char *cap_string(char *str)
{
	int i = 1;
	char sep[] = " \t\n,;.!?\"(){}";
	int j;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;

	while (str[i] != '\0')
	{
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (str[i - 1] == sep[j] &&
			    str[i] >= 'a' &&
			    str[i] <= 'z')
			{
				str[i] -= 32;
				break;
			}
		}
		i++;
	}

	return (str);
}
