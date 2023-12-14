#include "monty.h"

/**
* rotl - rotates the last node of a stack_t stack
* @stack: stack head
* @line_cnt: line count
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *last = *stack;
	stack_t *current = NULL;

	if (!stack || !*stack || !(*stack)->next)
		return;
	while (last->next)
	{
		current = last;
		last = last->next;
	}
	current->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/**
* rotr - rotates the first element of the stack
* @stack: stack head
* @line_cnt: line count
*
* Return: void
*/
void rotr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *tmp = *stack;
	stack_t *current = temp->next;


	if (!stack || !*stack || !(*stack)->next)
		return;
	while (tmp->next)
		tmp = tmp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	*stack = current;
	current->prev = NULL;

}
