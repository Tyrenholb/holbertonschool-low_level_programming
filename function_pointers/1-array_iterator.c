#include "function_pointers.h"
#include <stddef.h>

/**
 *array_iterator - Runs a function on each array element
 *@array: The array
 *@size: Number of elements
 *@action: Function to run
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	i = 0;
	while (i < size)
	{
		action(array[i]);
		i++;
	}
}
