#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given
 * position in a dlistint_t linked list.
 * @h: Pointer to the pointer to the head of the list.
 * @idx: Index of the position where the new node should be added.
 * @n: Data of the new node.
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *temp = *h;
unsigned int i;

if (idx == 0)
return (NULL);

for (i = 0; i < idx - 1 && temp != NULL; i++)
temp = temp->next;

if (temp == NULL)
return (NULL);

if (temp->next == NULL)
return (add_dnodeint_end(h, n));

new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->prev = temp;
new_node->next = temp->next;
temp->next->prev = new_node;
temp->next = new_node;

return (new_node);
}

