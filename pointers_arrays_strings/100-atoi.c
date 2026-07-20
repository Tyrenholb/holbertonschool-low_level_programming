#include "main.h"

/**
* _atoi - converts a string to an integer
* @s: string to convert
*
* Return: converted integer, or 0 if no digits are found
*/
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int number = 0;
	int found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			number = number * 10 + (s[i] - '0');
		}
		else if (found)
		{
			break;
		}

		i++;
	}

	if (sign == -1)
		return (-number);

	return (number);
}
