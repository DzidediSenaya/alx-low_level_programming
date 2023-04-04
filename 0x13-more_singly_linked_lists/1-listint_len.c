#include "lists.h"

/**
 * listint_len - Returns the number of elements in
 * a linked  listint_t list
 * @h: A pointer to the head of the singly linked list
 * Return: The number of nodes in the singly linked  list
 */


size_t listint_len(const listint_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		len++;
		h = h->next;
	}

	return (len);
}

