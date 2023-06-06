#include "lists.h"

listint_t *create_node(int n);

/**
 * insert_node - inserts a node sorted in a linked list of ints
 * @head: double pointer to head of LL, needed for modification in edge
 * cases
 * @number: data for new node
 *
 * Return: pointer to newly created node, NULL on failure
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current_node = NULL, *new_node = NULL;

	if (!head)
		return (NULL);
	else if (!(*head))
	{
		new_node = create_node(number);
		*head = new_node;
		return (new_node);
	}
	current_node = *head;
	while (current_node)
	{
		/* need to insert at head */
		if (current_node->n >= number)
		{
			new_node = create_node(number);
			new_node->next = current_node;
			*head = new_node;
			return (new_node);
		}
		else if (current_node->n <= number)
		{
			if (!current_node->next || current_node->next->n >= number)
			{
				new_node = create_node(number);
				new_node->next = current_node->next;
				current_node->next = new_node;
				return (current_node->next);
			}
		}
		current_node = current_node->next;
	}
	return (NULL); /* failed */
}

/**
 * create_node - creates a new node for the LL
 * @n: data to insert into new node
 *
 * Return: pointer to newly allocated node
 */
listint_t *create_node(int n)
{
	listint_t *ret = NULL;

	ret = malloc(sizeof(listint_t));
	if (!ret)
		return (NULL);
	ret->next = NULL;
	ret->n = n;
	return (ret);
}
