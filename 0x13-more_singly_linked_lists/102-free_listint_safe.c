#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the pointer of the first node in the linked list
 *
 * This function frees a linked list pointed to by 'h', safely handling
 * cases where the list contains loops. It iterates through the list
 * and frees each node, updating the 'next' pointers to break the loops
 * before freeing the memory. The 'h' pointer is set to NULL after freeing
 * all the nodes.
 *
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	int diff;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}

