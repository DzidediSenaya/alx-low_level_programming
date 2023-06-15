#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given
 * index in a dlistint_t linked list.
 * @head: Pointer to the pointer to the head of the list.
 * @index: Index of the node to be deleted.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current = *head;

if (*head == NULL)
return (-1);

if (index == 0)
{
*head = (*head)->next;
if (*head != NULL)
(*head)->prev = NULL;
free(current);
return (1);
}

for (; index > 0 && current != NULL; index--)
current = current->next;

if (current == NULL)
return (-1);

current->prev->next = current->next;
if (current->next != NULL)
current->next->prev = current->prev;
free(current);

return (1);
}

