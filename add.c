#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * node_add - adds a node to the start of a stack_t stack
 * @stack: stack head
 * @n: new number to be added.
 *
 * Return: newly created node, if creation fails, the
 * function will return NULL.
 */
stack_t *node_add(stack_t **stack, const int n)
{

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	new_node->n = n;

	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}
**
 * add-last_node - adds a node to a stack_t at the top.
 * @stack: stack head
 * @n: number of the node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */
stack_t *add-last_node(stack_t **stack, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *stack;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		return (NULL);
	}
	new_node->n = n;

	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new_node;
		return (new_node);
	}

	while (temp != NULL)
	{
		if (!temp->next)
		{
			new_node->next = NULL;
			new_node->prev = temp;
			temp->next = new_node;
			break;
		}
		temp = temp->next;
	}

	return (new_node);
}
