<<<<<<< HEAD
#include <ctype.h>
#include "monty.h"
=======
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

>>>>>>> fe262551a1ea2f7244e7e14f48a407084cdf42dd
/**
* pop - pops the very top element of the stack
* @stack: stack given by main in start.c
* @line_cnt: line number for error messages
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *temp = *stack;

	if (*stack == NULL || temp == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
		free_data();
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	if (temp->next != NULL)
		(temp->next)->prev = NULL;
	free(temp);
}
/**
 * swap -  swaps data from top to previous
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_cnt)
{
	 stack_t *temp = *stack;
	 int num = 0;

        if (temp == NULL || temp->next == NULL)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		free_data();
                exit(EXIT_FAILURE);
        }
	num = temp->n;
	temp->n = (temp->next)->n;
	(temp->next)->n = num;
}
<<<<<<< HEAD
/**
 * is_digit - checks if a string is a digit
 * @str: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
=======
>>>>>>> fe262551a1ea2f7244e7e14f48a407084cdf42dd
