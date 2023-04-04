#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list.
 * @head: A pointer to the head of the list
 * Return: If the linked list is empty - 0
 * Else, return the head node's data
 */

int pop_listint(listint_t **head)
{
listint_t *temp;
int data;

if (*head == NULL)
return (0);

temp = *head;
data = (*head)->n;
*head = (*head)->next;

free(temp);

return (data);
}
