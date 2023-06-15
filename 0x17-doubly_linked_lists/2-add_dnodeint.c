#include <stddef.h>
#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a
 * dlistint_t list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: The value to store in the new node.
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, int n)
{
dlistint_t *new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->prev = NULL;
new_node->next = *head;

if (*head != NULL)
(*head)->prev = new_node;

*head = new_node;
return (new_node);
}



/**
 * dlistint_len - Returns the number of elements in a
 * linked dlistint_t list.
 * @h: Pointer to the head of the list.
 * Return: The number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t count = 0;

while (h != NULL)
{
count++;
h = h->next;
}

return (count);
}

