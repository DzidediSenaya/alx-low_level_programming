#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * (can handle loops)
 * @head: Pointer to the beginning of the list
 * Return: The number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *current = head, *next = NULL;

while (current && count < 1024)
{
count++, printf("[%p] %d\n", (void *)current, current->n);
next = current->next;

if (next >= current)
{
printf("-> [%p] %d\n", (void *)next, next->n);
break;
}

current = next;
}

return (count);
}

