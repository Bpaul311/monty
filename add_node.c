#include "monty.h"
#include <stdlib.h>
/**
 * add - add the top two elements of the stack
 * @stack: Double linked list
 * @line_cnt: File line execution
 */
void add(stack_t **stack, unsigned int line_cnt)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_cnt);
		free_data();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_cnt);
}
/**
 * is_ascii - check if it is ascii
 * @a: the value to check
 * Return: 1 if succesful and 0 otherwise
 */
int is_ascii(int a)
{
	int b = a;

	if (b >= 0 && b <= 255)
	{
		return (1);
	}
	return (0);
}
