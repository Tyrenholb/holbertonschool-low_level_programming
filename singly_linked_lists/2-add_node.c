#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: Pointer to the head of the list
 * @str: String to store in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return(NULL);
	}
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return(NULL);
	}
	unsigned int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	new_node->len = i;
	new_node->next = (*head);

	(*head) = new_node;

	return (new_node);
}
