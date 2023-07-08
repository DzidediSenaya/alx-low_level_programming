#include <stddef.h>
#include "hash_tables.h"

/**
 * key_index - Retrieves the index of a key in a hash table.
 * @key: The key to be indexed.
 * @size: The size of the hash table array.
 *
 * Return: The index at which the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash_val;

if (key == NULL || size == 0)
return (0);

hash_val = hash_djb2(key);
return (hash_val % size);
}

