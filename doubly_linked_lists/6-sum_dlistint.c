#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all data in a doubly linked list
 * @head: Pointer to the first node
 *
 * Return: Sum of all node values
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
