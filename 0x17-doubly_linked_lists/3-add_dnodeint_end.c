#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - Adds a new node at the end
 * of a dlistint_t list.
 * @head: Double pointer to the head of the list.
 * @n: Value to be assigned to the new node.
 * Return: Address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new_node, *temp;

/* Create a new node */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;

if (*head == NULL)
{
/* If the list is empty, make the new node the head */
new_node->prev = NULL;
*head = new_node;
}
else
{
/* Traverse the list to the last node */
temp = *head;
while (temp->next != NULL)
temp = temp->next;

/* Connect the new node at the end */
temp->next = new_node;
new_node->prev = temp;
}

return (new_node);
}

