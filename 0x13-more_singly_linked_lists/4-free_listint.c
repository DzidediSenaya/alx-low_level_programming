#include "lists.h"

/**
 * free_listint - Frees a listint_t list
 * @head: A pointer to the head of the listint_t list
 */

void free_listint(listint_t *head)
{
listint_t *current_node;

while (head)
{
current_node = head;
head = head->next;
free(current_node);
}
}
