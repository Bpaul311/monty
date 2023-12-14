#include "monty.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 * sub -  substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_cnt)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_cnt);
		free_data();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_cnt);
}

/**
 * div -  substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void div(stack_t **stack, unsigned int line_cnt)
{
        if (!*stack || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_cnt);
                free_data();
                exit(EXIT_FAILURE);
        }
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cnt);
		free_data();
		exit(EXIT_FAILURE);
	}	

        (*stack)->next->n = (*stack)->next->n / (*stack)->n;
        pop(stack, line_cnt);
}
/**
 * prod -  substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void prod(stack_t **stack, unsigned int line_cnt)
{
        if (!*stack || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_cnt);
                free_data();
                exit(EXIT_FAILURE);
        }
        (*stack)->next->n = (*stack)->next->n * (*stack)->n;
        pop(stack, line_cnt);
}
/**
 * mod-  substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_cnt)
{
        if (!*stack || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_cnt);
                free_data();
                exit(EXIT_FAILURE);
        }
        if (((*stack)->n) == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", line_cnt);
                free_data();
                exit(EXIT_FAILURE);
        }

        (*stack)->next->n = (*stack)->next->n % (*stack)->n;
        pop(stack, line_cnt);
}
