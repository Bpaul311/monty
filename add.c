#include "monty.h"
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
