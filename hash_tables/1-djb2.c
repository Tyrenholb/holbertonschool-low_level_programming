#include "hash_tables.h"

/**
 * hash_djb2 - Generates a hash value using the djb2 algorithm
 * @str: String to generate a hash value from
 *
 * Return: The generated hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}
