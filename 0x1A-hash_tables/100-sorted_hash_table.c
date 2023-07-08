#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the hash table array.
 *
 * Return: A pointer to the newly created sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    if (size == 0)
        return (NULL);

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Adds or updates an element in the sorted hash table.
 * @ht: The sorted hash table to add/update the element to.
 * @key: The key of the element.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *temp_node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    index = key_index((unsigned char *)key, ht->size);
    temp_node = ht->array[index];

    /* Check if the key already exists in the sorted hash table */
    while (temp_node != NULL)
    {
        if (strcmp(temp_node->key, key) == 0)
        {
            /* Update the value associated with the existing key */
            free(temp_node->value);
            temp_node->value = strdup(value);
            return (1);
        }
        temp_node = temp_node->next;
    }

    /* Create a new node and add it to the sorted linked list */
    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    new_node->sprev = NULL;
    new_node->snext = NULL;

    if (ht->shead == NULL)
    {
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else
    {
        if (strcmp(new_node->key, ht->shead->key) < 0)
        {
            new_node->snext = ht->shead;
            ht->shead->sprev = new_node;
            ht->shead = new_node;
        }
        else
        {
            temp_node = ht->shead;
            while (temp_node->snext != NULL &&
                   strcmp(new_node->key, temp_node->snext->key) > 0)
            {
                temp_node = temp_node->snext;
            }
            new_node->snext = temp_node->snext;
            if (temp_node->snext != NULL)
                temp_node->snext->sprev = new_node;
            else
                ht->stail = new_node;
            new_node->sprev = temp_node;
            temp_node->snext = new_node;
            new_node->sprev = temp_node;
        }
    }

    ht->array[index] = new_node;

    return (1);
}

/**
 * shash_table_get - Retrieves the value associated with a key in
 * the sorted hash table.
 * @ht: The sorted hash table to look into.
 * @key: The key to look for.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *node;
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

/**
 * shash_table_print - Prints the sorted hash table using the
 * sorted linked list.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    for (node = ht->shead; node != NULL; node = node->snext)
    {
        printf("'%s': '%s'", node->key, node->value);
        if (node->snext != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse
 * order using the sorted linked list.
 * @ht: The sorted hash table to print in reverse order.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    printf("{");
    for (node = ht->stail; node != NULL; node = node->sprev)
    {
        printf("'%s': '%s'", node->key, node->value);
        if (node->sprev != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes the sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *temp_node;

    if (ht == NULL)
        return;

    for (node = ht->shead; node != NULL;)
    {
        temp_node = node;
        node = node->snext;
        free(temp_node->key);
        free(temp_node->value);
        free(temp_node);
    }

    free(ht->array);
    free(ht);
}

