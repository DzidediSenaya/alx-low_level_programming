#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list and sets the head to NULL
 * @head: pointer to the pointer of the list
 * Return: number of nodes freed
 */

size_t free_listint_safe(listint_t **head)
{
	size_t count = 0;
	listint_t *temp, *current;

	if (head == NULL || *head == NULL)
		return (0);

	while (*head != NULL)
	{
		count++;
		current = *head;
		*head = (*head)->next;
		temp = *head;
		while (temp != NULL && temp < current)
		{
			count++;
			temp = temp->next;
		}
		free(current);
		if (current == temp)
		{
			*head = NULL;
			count++;
			break;
		}
	}
	return (count);
}
