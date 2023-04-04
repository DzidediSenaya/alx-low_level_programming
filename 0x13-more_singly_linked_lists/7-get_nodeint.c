#include "lists.h"

/**
 * get_nodeint_at_index -  a function that returns the
 * nth node of a listint_t linked list
 * @index: the index of the node, starting at 0
 * @head: a pointer to the head of the list
 * Return: NULL, if the node does noot exist
 * Else, return the nth node of the list
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
listint_t *current = head;
unsigned int i = 0;

while (current != NULL && i < index)
{
current = current->next;
i++;
}

if (current == NULL)
return (NULL);
else
return (current);
}
