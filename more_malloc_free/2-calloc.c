#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array and initializes it to zero.
 * @nmemb: Number of elements.
 * @size: Size of each element.
 *
 * Return: Pointer to allocated memory, or NULL on failure.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	char *temp;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	temp = ptr;

	for (i = 0; i < nmemb * size; i++)
		temp[i] = 0;

	return (ptr);
}
