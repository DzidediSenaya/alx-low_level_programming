#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list
 * @head: A pointer to the head of the listint_t list
 */

void free_listint2(listint_t **head)
{
listint_t *current = *head;
listint_t *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}

*head = NULL;
}
