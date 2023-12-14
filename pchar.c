#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * pstr - prints the contents of a stack_t stack as a string
 * @stack: stack given by main
 * @line_cnt: line counter for error messages
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *temp = *stack;

	(void) line_cnt;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		putchar((char) temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
/**
 * pchar - prints the int at the top of the stack as char
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_cnt);
		free_data();
		exit(EXIT_FAILURE);
	}
	if (is_ascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		free_data();
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}

