#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * index of a listint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node that should be deleted
 * Return: 1 if it succeeded
 * -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current = *head, *temp;
unsigned int i = 0;

if (*head == NULL)
{
return (-1);
}

if (index == 0)
{
*head = (*head)->next;
free(current);
return (1);
}

while (current != NULL && i < index - 1)
{
current = current->next;
i++;
}

if (current == NULL || current->next == NULL)
{
return (-1);
/*index is out of range*/
}

temp = current->next;
current->next = temp->next;
free(temp);

return (1);
}
