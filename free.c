#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * free_data - Clean all program mallocs
 *@var: Pointer to vars structure
 * Return: None
 */
void free_data(void)
{
	if (var.buffer != NULL)
		free(var.buffer);
	if (var.file != NULL)
		fclose(var.file);
	free(var.dictionary);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}

/**
 * create_instruction - Create new functions dictionary
 * Return: Dictionary pointer
 */
instruction_t *create_instruction()
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[4].opcode = "swap", ptr[4].f = swap;
	ptr[5].opcode = "add", ptr[5].f = add;
	ptr[6].opcode = "nop", ptr[6].f = NULL;
	ptr[7].opcode = "sub", ptr[7].f = sub;
	ptr[8].opcode = "div", ptr[8].f = div;
	ptr[9].opcode = "mul", ptr[9].f = prod;
	ptr[10].opcode = "mod", ptr[10].f = mod;
	ptr[11].opcode = "pchar", ptr[11].f = pchar;
	ptr[12].opcode = "pstr", ptr[12].f = pstr;
	ptr[13].opcode = "rotl", ptr[13].f = rotl;
	ptr[14].opcode = "rotr", ptr[14].f = rotr;
	ptr[15].opcode = "stack", ptr[15].f = stack_t;
	ptr[16].opcode = "queue", ptr[16].f = queue;
	ptr[17].opcode = NULL, ptr[17].f = NULL;

	return (ptr);
}

/**
 * call_function - Call Functions
 * @var: Global variables
 * @opcode: Command to execute
 * Return: None
 */
int call_function(vars *var, char *opcode)
{
	int i;

	for (i = 0; var->dict[i].opcode; i++)
		if (strcmp(opcode, var->dict[i].opcode) == 0)
		{
			if (!var->dict[i].f)
				return (EXIT_SUCCESS);
			var->dict[i].f(&var->head, var->line_cnt);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->line_cnt, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
/**
 *initialise - For initaialisation
 * @var: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int initialise(vars *var)
{
	var->file = NULL;
	var->buffer= NULL;
	var->temp = 0;
	var->dictionary = create_instruction();
	if (var->dictionary == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_cnt = 1;
	var->data_structure = 0;

	return (EXIT_SUCCESS);
}
