#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list
 * @head: A pointer to a pointer to the head of the list
 * @n: The integer value to be stored in the new node
 * Return: The address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node, *temp;

/* Memory allocation for the new node */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

/* Set the value of the new node */
new_node->n = n;

/* Set the next pointer of the new node to NULL */
new_node->next = NULL;

/* If the list is empty, set the head to the new node */
if (*head == NULL)
{
*head = new_node;
return (new_node);
}

/* Else, loop through the list to find the last node */
temp = *head;
while (temp->next != NULL)
temp = temp->next;

/* Set the next pointer of the last node to the new node */
temp->next = new_node;

return (new_node);
}
