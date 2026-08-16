#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the node at a given index
 * @head: Pointer to the first node
 * @index: Index of the node to return
 *
 * Return: Address of the node, or NULL if it does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);

		head = head->next;
		i++;
	}

	return (NULL);
}
