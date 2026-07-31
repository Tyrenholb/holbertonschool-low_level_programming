#include "function_pointers.h"

/**
 * int_index - Searches for an integer
 * @array: Array to search
 * @size: Number of elements
 * @cmp: Function used to teach each element
 *
 * Return: Index of the first match, or -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
		return (-1);

	i = 0;
	while (i < size)
	{
		if (cmp(array[i]) != 0)
			return (i);
		i++;
	}
	return (-1);
}
