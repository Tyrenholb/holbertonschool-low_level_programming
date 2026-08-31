#include "hash_tables.h"

/**
 * key_index - Calculates the index of a key
 * @key: The key to calculate the index for
 * @size: Size of the hash table array
 *
 * Return: The index where the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key,
			    unsigned long int size)
{
	return (hash_djb2(key) % size);
}
