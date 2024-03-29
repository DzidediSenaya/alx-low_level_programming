#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a
 * key in the hash table.
 * @ht: The hash table to look into.
 * @key: The key to look for.
 *
 * Return: The value associated with the key, or NULL
 * if key couldn't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
hash_node_t *node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

index = key_index((unsigned char *)key, ht->size);
node = ht->array[index];

/* Traverse the linked list at the index */
while (node != NULL)
{
if (strcmp(node->key, key) == 0)
return (node->value);
node = node->next;
}

return (NULL); /* Key not found */
}

